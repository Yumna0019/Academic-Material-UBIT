from eight_puzzle_problem import EightPuzzleProblem
from Depth_First_Search import Search
from modify_s_DFS import DFS

# Create an instance of the 8-puzzle problem
initial_state = [[1, 2, 3], [5, 8, 6], [0, 7, 4]]  # Example initial state
goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]     # Example goal state

eight_puzzle_problem = EightPuzzleProblem(initial_state, goal_state)

# Create an instance of the DFS strategy
dfs_strategy = DFS()

# Create a search object
dfs_search = Search(eight_puzzle_problem, dfs_strategy)

# Solve the problem using DFS
dfs_result = dfs_search.solveProblem()

# Print the result
if dfs_result:
    print("\nDFS Result:")
    dfs_search.printResult(dfs_result)
else:
    print("DFS: No solution found.")

# Get the number of expanded nodes
expanded_nodes = dfs_search.getExpandedNodes()
print("The number of expanded nodes:", expanded_nodes)
