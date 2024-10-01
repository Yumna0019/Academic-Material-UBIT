# Import necessary classes
from eight_puzzle_problem import EightPuzzleProblem
from breadth_first_search import BreadthFirstSearchStrategy
from modify_search import Search

# Create an instance of the 8-puzzle problem
initial_state = [[1, 2, 3], [5, 8, 6], [0, 7, 4]]  # initial state
goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]     # goal state

eight_puzzle_problem = EightPuzzleProblem(initial_state, goal_state)

# Create an instance of the breadth-first search strategy
breadth_first_search_strategy = BreadthFirstSearchStrategy()

# Create a search object
search = Search(eight_puzzle_problem, breadth_first_search_strategy)

# Print the initial state
print("Initial State:", initial_state)

# Solve the problem
result = search.solveProblem()

# Print the result if it's not None
if result:
    search.printResult(result)
    expanded_nodes = search.getExpandedNodes()
    print("Number of expanded nodes:", expanded_nodes)
else:
    print("No solution found.")
