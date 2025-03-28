
from abc import abstractmethod
class Environment(object):

    @abstractmethod
    def __init__(self, n):
        self.n = n
    def executeStep(self,n=1):
        raise NotImplementedError('action must be defined!')
    def executeAll(self):
        raise NotImplementedError('action must be defined!')
    def delay(self,n=100):
        self.delay = n

# # For the Two Room Vacuum Cleaner Environment
# from com.environment import Environment 
# from com.environment import Room 
# from com.agent import VaccumAgent

class TwoRoomVaccumCleanerEnvironment(Environment.Environment):
 
    def __init__(self, agent):
        self.r1 = Room.Room('A','dirty')
        self.r2 = Room.Room('B','dirty')
        self.agent = agent
        self.currentRoom = self.r1
        self.delay = 1000 
        self.step = 1
        self.action = ""
    def executeStep(self,n=1):
        for _ in range(0,n):
            self.displayPerception()
            self.agent.sense(self) 
            res = self.agent.act() 
            self.action = res
            if res == 'clean':
                self.currentRoom.status = 'clean' 
            elif res =='right':
                self.currentRoom = self.r2 
            else:
                self.currentRoom = self.r1 
                self.displayAction()
                self.step += 1

    def executeAll(self):
        raise NotImplementedError('action must be defined!') 
    def displayPerception(self):
        print("Perception at step %d is [%s,%s]"%(self.step,self.currentRoom.status,self.currentRoom.location))
    def displayAction(self):
        print("------- Action taken at step %d is [%s]" %(self.step,self.action))
    def delay(self,n=100):
        self.delay = n
        
#Room class
class Room:
        def __init__(self,location,status="dirty"):
            self.location = location 
            self.status = status
            
#Abstract agent

from abc import abstractmethod
class Agent(object):
    
    @abstractmethod 
    def __init__(self): 
        pass

    @abstractmethod
    def sense(self,environment):
        pass

    @abstractmethod 
    def act(self):
        pass

# Vaccum cleaner Agent
# from com.agent import Agent
class VaccumAgent(Agent.Agent):

    def __init__(self):  
        pass
    def sense(self,env):
        self.environment = env
    def act(self):
        if self.environment.currentRoom.status == 'dirty':
            return 'clean' 
        if self.environment.currentRoom.location =='A': 
            return 'right'
        return 'left'

# Test program
if __name__ == '__main__': 
    vcagent = VaccumAgent.VaccumAgent() 
    env =TwoRoomVaccumCleanerEnvironment(vcagent)
    env.executeStep(50)




#    -------------------------------------------------------------------------------------------------
#    ------------------------------        GPT CODE        -------------------------------------------
#    -------------------------------------------------------------------------------------------------

from abc import ABC, abstractmethod

class Environment(ABC):
    def __init__(self, n):
        self.n = n

    @abstractmethod
    def executeStep(self, n=1):
        raise NotImplementedError('Action must be defined!')

    @abstractmethod
    def executeAll(self):
        raise NotImplementedError('Action must be defined!')

    def delay(self, n=100):
        self.delay = n

class TwoRoomVaccumCleanerEnvironment(Environment):
    def __init__(self, agent):
        super().__init__(n=1000)  # Initialize the superclass
        self.r1 = Room('A', 'dirty')
        self.r2 = Room('B', 'dirty')
        self.agent = agent
        self.currentRoom = self.r1
        self.step = 1
        self.action = ""

    def executeStep(self, n=1):
        for _ in range(n):
            self.displayPerception()
            self.agent.sense(self)
            res = self.agent.act()
            self.action = res
            if res == 'clean':
                self.currentRoom.status = 'clean'
            elif res == 'right':
                self.currentRoom = self.r2
            else:
                self.currentRoom = self.r1
            self.displayAction()
            self.step += 1

    def executeAll(self):
        raise NotImplementedError('Action must be defined!')

    def displayPerception(self):
        print("Perception at step %d is [%s,%s]" % (self.step, self.currentRoom.status, self.currentRoom.location))

    def displayAction(self):
        print("------- Action taken at step %d is [%s]" % (self.step, self.action))

class Room:
    def __init__(self, location, status="dirty"):
        self.location = location
        self.status = status

class Agent(ABC):
    @abstractmethod
    def __init__(self):
        pass

    @abstractmethod
    def sense(self, environment):
        pass

    @abstractmethod
    def act(self):
        pass

class VaccumAgent(Agent):
    def __init__(self):
        super().__init__()  # Initialize the superclass

    def sense(self, env):
        self.environment = env

    def act(self):
        if self.environment.currentRoom.status == 'dirty':
            return 'clean'
        if self.environment.currentRoom.location == 'A':
            return 'right'
        return 'left'

# Test program
if __name__ == '__main__':
    vcagent = VaccumAgent()
    env = TwoRoomVaccumCleanerEnvironment(vcagent)
    env.executeStep(5)  # Adjusted to execute fewer steps for demonstration purposes
