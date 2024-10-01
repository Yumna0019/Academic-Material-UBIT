from search_node import Node

class Search(object):
    '''
    classdocs
    '''

    def __init__(self, searchProblem, searchStrategy):
        '''
        Constructor
        '''
        self.searchProblem = searchProblem
        self.searchStrategy = searchStrategy
        self.expanded_nodes = 0  # Counter for expanded nodes

    def solveProblem(self):
        node = Node(self.searchProblem.initialState(), None, 0, 0, '')
        self.searchStrategy.addNode(node)
        self.expanded_nodes += 1  # Increment counter for initial node

        duplicateMap = {}
        duplicateMap[node.state.stringRep()] = node.state.stringRep()

        result = None

        while not self.searchStrategy.isEmpty():
            currentNode = self.searchStrategy.removeNode()
            self.expanded_nodes += 1  # Increment counter for each removed node

            if self.searchProblem.isGoal(currentNode.state):
                result = currentNode
                break

            nextMoves = self.searchProblem.successorFunction(currentNode.state)

            for nextState in nextMoves:
                if nextState.stringRep() not in duplicateMap:
                    newNode = Node(nextState, currentNode, currentNode.depth + 1,
                                   currentNode.cost + nextState.cost, nextState.action)
                    self.searchStrategy.addNode(newNode)
                    duplicateMap[newNode.state.stringRep()] = newNode.state.stringRep()

        return result

    def printResult(self, result):
        if result.parentNode is None:
            print("Game Starts")
        print("Initial State : %s" % result.state.getCurrentState())
        if result.parentNode:
            self.printResult(result.parentNode)
        print("Perform the following action %s, New State is %s, cost is %d" % (
            result.action, result.state.getCurrentState(), result.cost))

    def getExpandedNodes(self):
        return self.expanded_nodes
