import random

def generate_maze(rows, cols):
    # Generate a random maze (0 for walls, 1 for paths)
    maze = [[random.choice([0, 1]) for _ in range(cols)] for _ in range(rows)]
    maze[0][0] = 1  # Starting point
    maze[-1][-1] = 1  # Goal
    return maze

def is_valid_move(maze, row, col):
    rows = len(maze)
    cols = len(maze[0])
    return 0 <= row < rows and 0 <= col < cols and maze[row][col] == 1

def solve_maze(maze):
    rows = len(maze)
    cols = len(maze[0])
    visited = [[False for _ in range(cols)] for _ in range(rows)]

    def dfs(row, col):
        if not is_valid_move(maze, row, col) or visited[row][col]:
            return False
        if (row, col) == (rows - 1, cols - 1):
            return True
        
        visited[row][col] = True

        # Explore neighbors
        for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            if dfs(row + dr, col + dc):
                return True
        
        return False
    
    return dfs(0, 0)

def main():
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))

    maze = generate_maze(rows, cols)
    print("Generated Maze:")
    for row in maze:
        print(" ".join(map(str, row)))

    solvable = solve_maze(maze)
    if solvable:
        print("The maze is solvable!")
    else:
        print("The maze is not solvable.")

if __name__ == "__main__":
    main()
