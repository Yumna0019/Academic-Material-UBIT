from abc import ABC, abstractmethod

class SearchState(ABC):
    '''
    classdocs
    '''

    @abstractmethod
    def __init__(self, params):
        pass

    @abstractmethod
    def getCurrentState(self):
        pass

    @abstractmethod
    def getAction(self):
        pass

    @abstractmethod
    def getCost(self):
        pass

    @abstractmethod
    def stringRep(self):
        pass
