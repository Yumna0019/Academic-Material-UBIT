from eight_puzzle_problem import EightPuzzleProblem
from Uniform_Cost_Search import UCS
from Modify_S_UCS import Search

class Node:
    def __init__(self, state, parent=None, action=None, cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.cost = cost
# Create an instance of the 8-puzzle problem
initial_state = [[1, 2, 3], [5, 8, 6], [0, 7, 4]]  # initial state
goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]     # goal state

# Create an instance of the 8-puzzle problem
eight_puzzle_problem = EightPuzzleProblem(initial_state, goal_state)

# Create an instance of the Uniform Cost Search strategy
ucs_strategy = UCS()

# Create a search object using UCS strategy
ucs_search = Search(eight_puzzle_problem, ucs_strategy)
# Solve the problem using UCS
ucs_result = ucs_search.solveProblem()
if ucs_result is not None:
    print("\nUniform Cost Search Result:")
    ucs_search.printResult(ucs_result)
else:
    print("Uniform Cost Search: No solution found.")

# Get the number of expanded nodes
expanded_nodes = ucs_search.getExpandedNodes()
print("The number of expanded nodes:", expanded_nodes)