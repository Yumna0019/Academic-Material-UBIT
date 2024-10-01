from search_node import Node

class Search(object):
    def __init__(self, searchProblem, searchStrategy):
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
            """
            Print the result of the search.
            """
            current_node = result
            path = []
            while current_node is not None:
                path.append(current_node.state.getCurrentState())
                current_node = current_node.parentNode

            path.reverse()

            for i, state in enumerate(path):
                print(f"Step {i}: {state}")
                
                # Check if current_node has reached the root node
                if current_node is None:
                    break  # Exit the loop if the root node is reached

    def getExpandedNodes(self):
        return self.expanded_nodes
