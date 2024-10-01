from queue import PriorityQueue
from search_strategy import SearchStrategy

class UCS(SearchStrategy):
    '''
    classdocs
    '''
    def __init__(self):
        self.priorityQueue = PriorityQueue()
    
    def isEmpty(self):
        return self.priorityQueue.empty()
    
    def addNode(self, node):
        unique_id = id(node)  # Get a unique identifier for the node
        return self.priorityQueue.put((node.cost, unique_id, node))

    # def removeNode(self):
        # return self.priorityQueue.get()[1]
    
    def removeNode(self):
        return self.priorityQueue.get()

    
    