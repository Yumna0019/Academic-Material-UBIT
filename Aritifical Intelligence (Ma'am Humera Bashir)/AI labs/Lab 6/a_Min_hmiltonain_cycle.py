import itertools

# Example graph represented as an adjacency matrix
graph = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

def calculate_cost(path):
    cost = 0
    for i in range(len(path) - 1):
        cost += graph[path[i]][path[i+1]]
    cost += graph[path[-1]][path[0]]  # Return to the starting point
    return cost

def minimum_hamiltonian_cycle(graph):
    n = len(graph)
    min_cost = float('inf')
    min_path = None

    # Generate permutations of cities
    for perm in itertools.permutations(range(1, n)):
        cycle = [0] + list(perm)  # City 1 is always the starting and ending point
        cost = calculate_cost(cycle)
        if cost < min_cost:
            min_cost = cost
            min_cycle = cycle
    return min_cycle, min_cost

# Example usage
min_cycle, min_cost = minimum_hamiltonian_cycle(graph)
print("Minimum weight Hamiltonian Cycle:", min_cycle)
print("Minimum cost:", min_cost)