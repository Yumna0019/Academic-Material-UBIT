def is_safe(board, row, col, N):
    # Check if there is a queen in the same row
    for i in range(col):
        if board[row][i] == 1:
            return False
    
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check lower diagonal on left side
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_n_queens_util(board, col, N, solutions):
    # Base case: If all queens are placed
    if col >= N:
        solutions.append([row[:] for row in board])
        return
    
    # Try every row in the current column
    for i in range(N):
        if is_safe(board, i, col, N):
            # Place the queen in this row and column
            board[i][col] = 1
            
            # Recur to place the rest of the queens
            solve_n_queens_util(board, col + 1, N, solutions)
            
            # If placing the queen here doesn't lead to a solution,
            # backtrack and try other rows
            board[i][col] = 0

def solve_n_queens(N):
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []
    
    solve_n_queens_util(board, 0, N, solutions)

    if not solutions:
        print("Solution does not exist")
        return
    
    total_solutions = len(solutions)
    print("Total number of solutions:", total_solutions)
    print("Some solutions are:")

    # Show only 2 to 3 solutions
    for solution in solutions[:2]:
        for row in solution:
            print(row)
        print()
        if total_solutions >= 3:
            total_solutions -= 1
        else:
            break

# Example :
n = 10 
solve_n_queens(n)
