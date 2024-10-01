from abc import abstractmethod

class Agent(object):
    @abstractmethod
    def _init_(self):
        pass  

    @abstractmethod
    def sense(self, environment):
        pass  

    @abstractmethod
    def act(self):
        pass  

class VacuumAgent(Agent):
    def _init_(self):
        pass  

    def sense(self, env):
        self.environment = env  # Store the environment the agent senses

    def act(self):
        # If the current room is dirty, clean it
        if self.environment.currentRoom.status == 'dirty':
            return 'clean'
        # If the agent is in room A or B, move right
        if self.environment.currentRoom.location == 'A' or self.environment.currentRoom.location == 'B':
            return 'right'
        # If not in room A or B, default to moving left
        return 'left'
