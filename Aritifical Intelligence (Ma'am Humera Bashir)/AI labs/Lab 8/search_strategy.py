from abc import ABC, abstractmethod

class SearchStrategy(ABC):
    '''
    classdocs
    '''

    @abstractmethod
    def __init__(self, params):
        pass

    @abstractmethod
    def isEmpty(self):
        pass

    @abstractmethod
    def addNode(self, node):
        pass

    @abstractmethod
    def removeNode(self):
        pass
