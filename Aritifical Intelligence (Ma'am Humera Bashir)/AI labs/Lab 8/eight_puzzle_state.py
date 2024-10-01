from search_state import SearchState

class EightPuzzleState(SearchState): 
    '''
    classdocs
    '''
    def __init__(self, currentState, action, cost):
        '''
        Constructor
        '''
        # Initialize the current state of the Eight Puzzle
        self.currentState = currentState
        # Store the action taken to reach this state
        self.action = action
        # Store the cost associated with reaching this state
        self.cost = cost
        # Initialize the string representation of the state to None
        self.string = None

    def getCurrentState(self):
        # Return the current state of the Eight Puzzle
        return self.currentState

    def getAction(self):
        # Return the action taken to reach this state
        return self.action

    def getCost(self):
        # Return the cost associated with reaching this state
        return self.cost

    def stringRep(self):
        # Check if the string representation of the state has been computed
        if self.string is None:
            # If not, compute it
            e = ''
            for i in range(len(self.currentState)):
                for j in range(len(self.currentState[i])):
                    e += str(self.currentState[i][j])
            # Store the computed string representation
            self.string = e
        # Return the string representation
        return self.string
