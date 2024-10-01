from search_problem import SearchProblem
import copy
from eight_puzzle_state import EightPuzzleState

class EightPuzzleProblem(SearchProblem):
    '''
    classdocs
    '''

    def __init__(self, initialState, goalState):
        '''
        Constructor
        '''
        # Initialize the initial state of the puzzle with an EightPuzzleState object
        self._initialState = EightPuzzleState(initialState, '', 0) 
        # Set the goal state of the puzzle
        self._goalState = goalState
        # Calculate and store the number of rows in the initial state
        self._numberOfRows = len(initialState)
        # Calculate and store the number of columns in the initial state
        self._numberOfColumns = len(initialState[0])

    def initialState(self):
        # Return the initial state of the puzzle
        return self._initialState

    def successorFunction(self, cs): #successor states (possible moves)
        # Initialize an empty list to store successor states
        nextMoves = []
        # Initialize variables to store the row and column of the empty cell
        emptyRow, emptyColumn = 0, 0
        # Get the current state of the puzzle
        currentState = cs.currentState

        # Flag to track if the empty cell is found
        emptyFound = False

        # Iterate over the rows and columns of the current state
        for i in range(len(currentState)):
            for j in range(len(currentState[i])):
                # Check if the cell is empty (contains 0)
                if currentState[i][j] == 0:
                    # Store the row and column of the empty cell
                    emptyRow, emptyColumn = i, j
                    # Set the flag to True indicating that the empty cell is found
                    emptyFound = True
                    # Break out of the inner loop
                    break
            # Check if the empty cell is found
            if emptyFound:
                # Break out of the outer loop
                break

        # Check up move
        if emptyRow != 0:
            # Create a new state by moving the empty cell up
            newState = copy.deepcopy(currentState)
            tempS = newState[emptyRow - 1][emptyColumn]
            newState[emptyRow - 1][emptyColumn] = 0
            newState[emptyRow][emptyColumn] = tempS
            # Create an EightPuzzleState object representing the new state and add it to the list of next moves
            ep = EightPuzzleState(newState, 'Move Up', 1.0)
            nextMoves.append(ep)

        # Check down move
        if emptyRow + 1 != self._numberOfRows:
            # Create a new state by moving the empty cell down
            newState = copy.deepcopy(currentState)
            tempS = newState[emptyRow + 1][emptyColumn]
            newState[emptyRow + 1][emptyColumn] = 0
            newState[emptyRow][emptyColumn] = tempS
            # Create an EightPuzzleState object representing the new state and add it to the list of next moves
            ep = EightPuzzleState(newState, 'Move Down', 1.0)
            nextMoves.append(ep)

        # Check left move
        if emptyColumn != 0:
            # Create a new state by moving the empty cell left
            newState = copy.deepcopy(currentState)
            tempS = newState[emptyRow][emptyColumn - 1]
            newState[emptyRow][emptyColumn - 1] = 0
            newState[emptyRow][emptyColumn] = tempS
            # Create an EightPuzzleState object representing the new state and add it to the list of next moves
            ep = EightPuzzleState(newState, 'Move Left', 1.0)
            nextMoves.append(ep)

        # Check right move
        if emptyColumn + 1 != self._numberOfColumns:
            # Create a new state by moving the empty cell right
            newState = copy.deepcopy(currentState)
            tempS = newState[emptyRow][emptyColumn + 1]
            newState[emptyRow][emptyColumn + 1] = 0
            newState[emptyRow][emptyColumn] = tempS
            # Create an EightPuzzleState object representing the new state and add it to the list of next moves
            ep = EightPuzzleState(newState, 'Move Right', 1.0)
            nextMoves.append(ep)

        # Return the list of successor states
        return nextMoves

    def isGoal(self, currentState):
        # Get the current state of the puzzle
        cs = currentState.getCurrentState()
        # Iterate over the rows and columns of the current state
        for i in range(len(cs)):
            for j in range(len(cs[i])):
                # Check if the cell in the current state matches the corresponding cell in the goal state
                if cs[i][j] != self._goalState[i][j]:
                    # If any cell does not match, return False indicating that the goal is not reached
                    return False
        # If all cells match, return True indicating that the goal state is reached
        return True
    def __str__(self):
        return f"Initial State: {self._initialState}\nGoal State: {self._goalState}"
