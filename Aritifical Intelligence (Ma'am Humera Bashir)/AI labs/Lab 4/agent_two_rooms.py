# Represents an agent operating in the environment.
from abc import abstractmethod

class Agent(object): 
    @abstractmethod
    def __init__(self):  
        pass  
    @abstractmethod
    def sense(self, environment):   
        pass  

    @abstractmethod
    def act(self):   
        pass  # Performs an action in the environment based on the sensed information (abstract).

class VacuumAgent(Agent):
    def _init_(self):
        pass  # Initializes the vacuum agent (currently does nothing).

    def sense(self, envn):   
        self.environment = envn 

    def act(self):   
        # Performs cleaning or movement actions based on the current room's status and location.
        if self.environment.currentRoom.status == 'dirty':
            return 'clean'
        if self.environment.currentRoom.location == 'A':
            return 'right'
        return 'left'
