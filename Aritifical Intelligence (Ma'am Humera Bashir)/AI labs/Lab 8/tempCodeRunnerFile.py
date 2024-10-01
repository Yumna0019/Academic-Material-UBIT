if result:
    search.printResult(result)
    expanded_nodes = search.getExpandedNodes()
    print("Number of expanded nodes:", expanded_nodes)
else:
    print("No solution found.")
Modify the printResult method to print the initial state only once before the search begins