# Represents a room in the environment.
class Room:   
    def __init__(self, location, status="dirty"):
        self.location = location  # Location of the room (e.g., A, B, etc.).
        self.status = status      # Status of the room (e.g., dirty or clean).

from abc import abstractmethod

class Environment(object):  
    @abstractmethod
    def __init__(self, n):
        self.n = n  # Initializes the environment with 'n' rooms.

    @abstractmethod
    def executeStep(self, n=1):          
        raise NotImplementedError('action must be defined!')

    @abstractmethod
    def executeAll(self):      
        raise NotImplementedError('action must be defined!')

    @abstractmethod
    def delay(self, n=100):     
        self.delay = n
