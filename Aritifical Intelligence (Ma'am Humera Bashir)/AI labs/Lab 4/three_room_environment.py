from environment import Environment  # Importing the Environment class from the environment module
from environment import Room  # Importing the Room class from the environment module
from agent_three_rooms import VacuumAgent  # Importing the VacuumAgent class from the agent_for_three_rooms module

class ThreeRoomVacuumCleanerEnvironment(Environment):
    def __init__(self, agent):
        self.r1 = Room('A', 'dirty')  
        self.r2 = Room('B', 'dirty')  
        self.r3 = Room('C', 'dirty')  
        self.agent = agent  # Assigns the agent to the environment
        self.currentRoom = self.r1  # Sets the current room to the first room
        self.delay = 1000  
        self.step = 1  
        self.action = "" 

    def executeStep(self, n=1):
        # n: Number of steps to execute (default is 1).
        for _ in range(0, n):
            self.displayPerception()  # Displays the perception of the environment
            self.agent.sense(self)  # Sends the environment information to the agent
            res = self.agent.act()  # Retrieves action from the agent
            self.action = res  # Stores the action
            if res == 'clean':
                self.currentRoom.status = 'clean'  # Updates the current room status if it's cleaned
            elif res == 'right':
                self.move_right()  # Moves the agent to the right room
            elif res == 'left':
                self.move_left()  # Moves the agent to the left room
            self.displayAction()  # Displays the action taken
            self.step += 1  # Increments the step counter

    def displayPerception(self):
        # Display the current perception of the environment.
        print("Perception at step %d is [%s, %s]" % (self.step, self.currentRoom.status, self.currentRoom.location))

    def displayAction(self):
        # Display the action taken by the agent at the current step.
        print("------- Action taken at step %d is [%s]" % (self.step, self.action))

    def move_right(self):
        # Move the agent to the room on the right based on the current room.
        if self.currentRoom == self.r1:
            self.currentRoom = self.r2
        elif self.currentRoom == self.r2:
            self.currentRoom = self.r3

    def move_left(self):
        # Move the agent to the room on the left based on the current room.
        if self.currentRoom == self.r3:
            self.currentRoom = self.r2
        elif self.currentRoom == self.r2:
            self.currentRoom = self.r1

# Test program
if __name__ == '__main__':
    vcagent = VacuumAgent() 
    env = ThreeRoomVacuumCleanerEnvironment(vcagent) 
    env.executeStep(50)  
