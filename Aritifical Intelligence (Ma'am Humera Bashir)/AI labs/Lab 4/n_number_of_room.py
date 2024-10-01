from environment import Environment  # Importing Environment class from environment module
from environment import Room  # Importing Room class from environment module
from agent_for_n_rooms import VaccumAgent1  # Importing VacuumAgent1 class from agent_for_n_rooms module

class NRoomVacuumCleanerEnvironment(Environment):
    def __init__(self, agent, num_rooms=5):
        self.rooms = [Room(chr(ord('A') + i), 'dirty') for i in range(num_rooms)]  # Creates a list of rooms with specified location and status
        self.agent = agent  
        self.currentRoom = self.rooms[0]  # Sets the current room to the first room
        self.delay = 1000  
        self.step = 1  
        self.action = ""  

    def executeStep(self, n=1):
        for _ in range(0, n):
            self.displayPerception()  # Displays the perception of the environment
            self.agent.sense(self)  # Sends the environment information to the agent
            res = self.agent.act()  # Retrieves action from the agent
            self.action = res  # Stores the action
            if res == 'clean':
                self.currentRoom.status = 'clean'  # Updates the current room status if it's cleaned
            elif res == 'right':
                self.currentRoom = self.get_next_room()  # Moves to the next room if 'right' action is performed
            else:
                self.currentRoom = self.get_previous_room()  # Moves to the previous room if 'left' action is performed
            self.displayAction()  # Displays the action taken
            self.step += 1  # Increments the step counter

    def displayPerception(self):
        print(f"Perception at step {self.step} is [{self.currentRoom.status}, {self.currentRoom.location}]")  # Displays the perception of the environment

    def displayAction(self):
        print(f"------- Action taken at step {self.step} is [{self.action}]")  # Displays the action taken

    def delay(self, n=100):
        self.delay = n  # Sets the delay time

    def get_next_room(self):  # Finds the next room in a cyclic manner based on the current room
        index = (self.rooms.index(self.currentRoom) + 1) % len(self.rooms)
        return self.rooms[index]

    def get_previous_room(self):  # Finds the previous room in a cyclic manner based on the current room
        index = (self.rooms.index(self.currentRoom) - 1) % len(self.rooms)
        return self.rooms[index]

# Test program
if __name__ == '__main__':
    vcagent = VaccumAgent1()  
    env = NRoomVacuumCleanerEnvironment(vcagent) 
    env.executeStep(10)  
