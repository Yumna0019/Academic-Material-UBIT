from abc import ABC, abstractmethod

class SearchProblem(ABC):

    @abstractmethod
    def __init__(self, params):
        pass

    @abstractmethod
    def initialState(self):
        pass

    @abstractmethod
    def successorFunction(self, currentState):
        pass

    @abstractmethod
    def isGoal(self, currentState):
        pass

    @abstractmethod
    def __str__(self):
        pass
