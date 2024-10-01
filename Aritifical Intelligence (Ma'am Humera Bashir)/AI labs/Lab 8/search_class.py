from search_node import Node  # Importing the Node class from search_node module
from eight_puzzle_problem import EightPuzzleProblem  # Importing the EightPuzzleProblem class from eight_puzzle_problem module
from breadth_first_search import BreadthFirstSearchStrategy  # Importing the BreadthFirstSearchStrategy class from breadth_first_search module

class Search(object):  
    ''' 
    classdocs 
    '''

    def __init__(self, searchProblem, searchStrategy):
        ''' 
        Constructor 
        '''
        self.searchProblem = searchProblem  # Initializing the search problem
        self.searchStrategy = searchStrategy  # Initializing the search strategy

    def solveProblem(self):
        # Creating a node with the initial state of the search problem
        node = Node(self.searchProblem.initialState(), None, 0, 0, '')  
        self.searchStrategy.addNode(node)  # Adding the initial node to the search strategy

        duplicateMap = {}  # Creating a dictionary to keep track of duplicate states
        duplicateMap[node.state.stringRep()] = node.state.stringRep()  # Storing the string representation of the initial state

        result = None  # Initializing the result variable

        while not self.searchStrategy.isEmpty():
            currentNode = self.searchStrategy.removeNode()  # Removing a node from the search strategy

            if self.searchProblem.isGoal(currentNode.state):  # Checking if the current node's state is the goal state
                result = currentNode  # Assigning the current node as the result
                break

            nextMoves = self.searchProblem.successorFunction(currentNode.state)  # Generating successor states

            for nextState in nextMoves:
                if nextState.stringRep() not in duplicateMap:
                    # Creating a new node for the successor state
                    newNode = Node(nextState, currentNode, currentNode.depth + 1,
                                   currentNode.cost + nextState.cost, nextState.action)
                    self.searchStrategy.addNode(newNode)  # Adding the new node to the search strategy
                    duplicateMap[newNode.state.stringRep()] = newNode.state.stringRep()  # Storing the string representation of the new state
        
        return result  # Returning the result node

    def printResult(self, result):
        if result.parentNode is None:
            print("Game Starts")  # Printing a message indicating the start of the game
        print("Initial State : %s" % result.state.getCurrentState())  # Printing the initial state of the puzzle
        if result.parentNode:
            self.printResult(result.parentNode)  # Recursively printing the parent nodes
        print("Perform the following action %s, New State is %s, cost is %d" % (
            result.action, result.state.getCurrentState(), result.cost))  # Printing the action, new state, and cost of the result node
