from queue import LifoQueue
from search_strategy import SearchStrategy

class DFS(SearchStrategy):
    def __init__(self):
        self.stack = LifoQueue()

    def isEmpty(self):
        return self.stack.empty()

    def addNode(self, node):
        unique_id = id(node)  # Get a unique identifier for the node
        return self.stack.put((unique_id, node))

    def removeNode(self):
        return self.stack.get()[1]  # Get the node from the tuple
