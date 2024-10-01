#main
from environment import Environment  # Importing the Environment class from the environment module
from environment import Room  # Importing the Room class from the environment module
from agent_two_rooms import VacuumAgent  # Importing the VacuumAgent class from the agent_for_two_rooms module

class TwoRoomVacuumCleanerEnvironment(Environment):
    def __init__(self, agent):
        self.r1 = Room('A', 'dirty') 
        self.r2 = Room('B', 'dirty') 
        self.agent = agent 
        self.currentRoom = self.r1  # Sets the current room to the first room
        self.delay = 1000  
        self.step = 1  
        self.action = ""  

    def executeStep(self, n=1):
        for _ in range(0, n):  # Loops through the specified number of steps
            self.displayPerception()  # Displays the perception of the environment
            self.agent.sense(self)  # Sends the environment information to the agent
            res = self.agent.act()  # Retrieves action from the agent
            self.action = res  # Stores the action
            if res == 'clean':
                self.currentRoom.status = 'clean'  # Updates the current room status if it's cleaned
            elif res == 'right':
                self.currentRoom = self.r2  # Moves to the second room if 'right' action is performed
            else:
                self.currentRoom = self.r1  # Moves back to the first room if 'left' action is performed
            self.displayAction()  # Displays the action taken
            self.step += 1  # Increments the step counter


    def displayPerception(self):
        # Display the current perception of the environment.
        print("Perception at step %d is [%s, %s]" % (self.step, self.currentRoom.status, self.currentRoom.location))

    def displayAction(self):
        # Display the action taken by the agent at the current step.
        print("------- Action taken at step %d is [%s]" % (self.step, self.action))

# Test program
if __name__ == '__main__':
    vcagent = VacuumAgent() 
    env = TwoRoomVacuumCleanerEnvironment(vcagent) 
    env.executeStep(5)  
