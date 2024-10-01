# State representation: (cannibals_left, missionaries_left, boat_side)
# boat_side: 0 for left side, 1 for right side
# Initial state: (3, 3, 0)
# Goal state: (0, 0, 1)

def is_valid_state(state):
    cannibals_left, missionaries_left, _ = state
    if cannibals_left < 0 or missionaries_left < 0:
        return False
    if cannibals_left > 3 or missionaries_left > 3:
        return False
    if missionaries_left > 0 and missionaries_left < cannibals_left:
        return False
    if missionaries_left < 3 and missionaries_left > 0 and missionaries_left != cannibals_left:
        return False
    return True

def get_successor_states(state):
    successors = []
    cannibals_left, missionaries_left, boat_side = state
    possible_moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]

    if boat_side == 0: # boat on the left side
        for move in possible_moves:
            new_state = (cannibals_left - move[0], missionaries_left - move[1], 1)
            if is_valid_state(new_state):
                successors.append(new_state)
    else: # boat on the right side
        for move in possible_moves:
            new_state = (cannibals_left + move[0], missionaries_left + move[1], 0)
            if is_valid_state(new_state):
                successors.append(new_state)
    return successors

def dls(current_state, goal_state, depth):
    if current_state == goal_state:
        return [current_state]
    if depth <= 0:
        return None
    for successor_state in get_successor_states(current_state):
        result = dls(successor_state, goal_state, depth - 1)
        if result is not None:
            return [current_state] + result
    return None

def iddfs(start_state, goal_state):
    depth = 0
    while True:
        result = dls(start_state, goal_state, depth)
        if result is not None:
            return result
        depth += 1

def print_solution(path):
    print("Start: Cannibals: 3, Missionaries: 3, Boat: 1")
    for i, state in enumerate(path):
        cannibals_left, missionaries_left, boat_side = state
        print(f"Step {i}: Cannibals: {cannibals_left}, Missionaries: {missionaries_left}, Boat: {'1' if boat_side == 0 else '0'}")

def main():
    start_state = (3, 3, 0)
    goal_state = (0, 0, 1)
    solution = iddfs(start_state, goal_state)
    if solution:
        print("Solution found:")
        print_solution(solution)
    else:
        print("No solution found.")

if __name__ == "__main__":
    main()
