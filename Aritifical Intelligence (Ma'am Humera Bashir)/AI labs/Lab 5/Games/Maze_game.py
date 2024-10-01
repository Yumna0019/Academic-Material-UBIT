# HINT:
# ▸ Representation: Represent the maze as a 2D array of characters, where # represents a wall, . represents an open space, S-represents the starting position, and E represents the exit.
# State Space: Each state represents the robot's current position in the
# maze.
# › Actions: The robot can move up, down, left, or right in a single step, provided the new position is an open space.
# > Goal Test: The goal test checks if the robot's current position is the exit (E).
# > DFS Implementation: Implement a Depth-First Search algorithm to explore the maze. The algorithm maintains a stack to keep track of the explored path. At each step, it pops a state from the stack, checks if it's the goal (exit), and explores its unvisited neighbors by pushing them onto the stack.



import os
import msvcrt

class MazeGame:
    def __init__(self, maze):
        self.maze = maze
        self.rows = len(maze)
        self.cols = len(maze[0])
        self.visited = set()
        self.user_pos = (1, 0)

    def print_maze(self):
        os.system('cls' if os.name == 'nt' else 'clear')  # Clear the terminal
        for i in range(self.rows):
            for j in range(self.cols):
                if (i, j) == self.user_pos:
                    print('O', end=' ')  # Print user's position
                else:
                    print(self.maze[i][j], end=' ')
            print()
    
    def is_valid_move(self, position):
        x, y = position
        if 0 <= x < self.rows and 0 <= y < self.cols and self.maze[x][y] != '#':
            return True
        return False
    
    def move(self, direction):
        x, y = self.user_pos
        if direction == b'w':    # up
            new_pos = (x-1, y)
        elif direction == b's':  # down
            new_pos = (x+1, y)
        elif direction == b'a':  # left
            new_pos = (x, y-1)   
        elif direction == b'd':  # right
            new_pos = (x, y+1)   
        else:
            return
        
        if self.is_valid_move(new_pos):
            self.user_pos = new_pos
    
    def play(self):
        self.print_maze()
        while True:
            direction = msvcrt.getch()
            if direction == b'q':  # Quit if 'q' is pressed
                break
            self.move(direction)
            self.print_maze()
            if self.maze[self.user_pos[0]][self.user_pos[1]] == 'E':
                print("Congratulations! You reached the exit!")
                break

def main():
    maze = [
        ['#', '#', '#', '#', '#', '#', '#', '#', '#', '#'],
        ['.', '.', '.', '.', '#', '.', '.', '.', '.', '#'],
        ['#', '.', '#', '.', '#', '.', '#', '#', '.', '#'],
        ['#', '.', '#', '.', '.', '.', '.', '.', '.', '#'],
        ['#', '#', '#', '#', '.', '#', '#', '#', '#', '#'],
        ['#', '.', '.', '#', '.', '.', '.', '#', '.', '#'],
        ['#', '#', '.', '#', '.', '#', '.', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '#', '.', '.', '.', 'E'],
        ['#', '#', '#', '#', '#', '#', '#', '#', '#', '#'],
    ]
    
    game = MazeGame(maze)
    game.play()

if __name__ == "__main__":
    main()
