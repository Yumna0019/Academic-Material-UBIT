import random

class Process:
    def __init__(self, PN, PC, IR, AT, ET, State, SA, PSRI, PSRA, i, resource_info=None, resource_index=None):
        self.PN = PN
        self.PC = PC  # Program Counter
        self.IR = IR
        self.AT = AT
        self.ET = ET  # Execution Time
        self.State = State
        self.SA = SA
        self.PSRI = PSRI  # Process State Register Instruction
        self.PSRA = PSRA  # Process State Register Address
        self.i = i
        self.remaining_time = ET
        self.resume_index = 0  # To keep track of where to resume execution
        self.resource_info = resource_info
        self.resource_index = resource_index

    def print_pcb(self):
        print(f"Process Control Block : {self.PN}")
        print(f"Process Id : {self.PN}")
        print(f"Program Counter : {self.PC}")
        print(f"Instruction Register: {self.IR}")
        print(f"Arrival Time : {self.AT}")
        print(f"Execution Time : {self.ET}")
        print(f"Remaining Time : {self.remaining_time}")
        print(f"Resource Info : {self.resource_info}")
        print(f"State : {self.State}")
        print(f"Scheduling Algorithm: {self.SA}")
        print(f"PSW (Resume Instruction) : {self.PSRI}")
        print(f"PSW (Resume Instruction Address) : {self.PSRA}\n")

    def run(self, quantum_size, Process_Ins, paused_instructions):
        if self.remaining_time > 0:
            # Determine how much time to execute
            executed_time = min(quantum_size, self.remaining_time)
            if self.resource_info == 1 and self.resume_index < self.resource_index:
                executed_time = min(executed_time, self.resource_index - self.resume_index)

            start_index = self.resume_index
            end_index = start_index + executed_time
            
            # Check if we hit the resource index during execution
            if self.resource_info == 1 and start_index + executed_time > self.resource_index:
                end_index = self.resource_index

            # Execute and update
            executed_elements = arrays[self.i][start_index:end_index]
            Process_Ins.extend(executed_elements)
            self.remaining_time -= (end_index - start_index)
            self.resume_index = end_index

            # Update PSRI and PSRA
            self.PSRI = arrays[self.i][self.resume_index - 1] if self.resume_index > 0 else 0
            self.PSRA = self.resume_index - 1
            
            # Print Process Control Block (PCB)
            self.print_pcb()
            print(f"Process_Ins : {Process_Ins}")
            
            # If we reached the resource index, yield to the next process and save paused instructions
            if self.resource_info == 1 and self.resume_index >= self.resource_index:
                print(f"{self.PN} reached resource index, yielding to next process.")
                paused_instructions.extend(arrays[self.i][self.resume_index:])  # Slice remaining elements
                self.State = "Waiting"
                self.remaining_time = 0  # Mark this process as done
                return  # Yield to the next process

def create_process_class(PN, PC, IR, AT, ET, State, SA, PSRI, PSRA, i, resource_info=None, resource_index=None):
    class CustomProcess(Process):
        def __init__(self):
            super().__init__(PN, PC, IR, AT, ET, State, SA, PSRI, PSRA, i, resource_info, resource_index)
    return CustomProcess


num_arrays = int(input("Enter the number of arrays you want to create (must be less than or equal to 5): "))
quantum_size = int(input("Enter quantum size (must be less than or equal to 3): "))
while quantum_size > 3:
    print("Size must be less than or equal to 3. Please try again.")
    quantum_size = int(input("Enter quantum size: "))

arrays = []
for i in range(num_arrays):
    execution_time = int(input(f"Enter the size of array {i + 1} (must be less than or equal to 10): "))
    while execution_time > 10:
        print("Size must be less than or equal to 10. Please try again.")
        execution_time = int(input(f"Enter the size of array {i + 1} (must be less than or equal to 10): "))
    array = [random.randint(0, 100) for _ in range(execution_time)]
    arrays.append(array)

def print_table():
    headers = ["Process", "Execution", "Arrival"]
    print(f"{headers[0].ljust(10)}| {headers[1].ljust(15)}| {headers[2].ljust(7)}")
    print("-" * 35)
    for idx, array in enumerate(arrays, 1):
        process_name = f"P{idx - 1}:{array}"
        execution = str(len(array))
        arrival = str(idx - 1)
        print(f"{process_name.ljust(10)}| {execution.ljust(15)}| {arrival.ljust(7)}")

print_table()

processes = []
for i in range(num_arrays):
    PN = f"P{i}"
    PC = 0  
    IR = f"P{i+1}[{i}]"
    AT = i
    ET = len(arrays[i])
    State = "Running"
    SA = "Round Robin"
    PSRI = 0
    PSRA = 0

    resource_info = int(input(f"Enter resource info for process {PN} (enter 0 if none): "))
    resource_index = None
    if resource_info != 0:
        resource_index = int(input(f"Enter the index where the resource is added for process {PN}: "))

    process_class = create_process_class(PN, PC, IR, AT, ET, State, SA, PSRI, PSRA, i, resource_info, resource_index)
    process_instance = process_class()
    processes.append(process_instance)


Process_Ins = []
paused_instructions = []  


process_index = 0  

while any(p.remaining_time > 0 for p in processes):
    current_process = processes[process_index]
    
    if current_process.State != "Waiting": 
        current_process.run(quantum_size, Process_Ins, paused_instructions)


    process_index = (process_index + 1) % num_arrays

if paused_instructions:
    print("Executing paused instructions:")
    paused_process = Process("Paused", 0, "Paused_IR", 0, len(paused_instructions), "Running", "Round Robin", 0, 0, 0,resource_info=0)
    paused_process.remaining_time = len(paused_instructions) 
    paused_process.resume_index = 0  

    while paused_process.remaining_time > 0:
        executed_time = min(quantum_size, paused_process.remaining_time)
        
        
        start_index = paused_process.resume_index
        end_index = start_index + executed_time

        if end_index > len(paused_instructions):
            end_index = len(paused_instructions)

        executed_elements = paused_instructions[start_index:end_index]
        Process_Ins.extend(executed_elements)
        
        paused_process.remaining_time -= (end_index - start_index)
        paused_process.resume_index = end_index

        paused_process.PSRI = paused_instructions[paused_process.resume_index - 1] if paused_process.resume_index > 0 else 0
        paused_process.PSRA = paused_process.resume_index - 1

        paused_process.print_pcb()
        print(f"Paused Process_Ins: {Process_Ins}, Remaining Time: {paused_process.remaining_time}")

print("Final Process_Ins:", Process_Ins)
