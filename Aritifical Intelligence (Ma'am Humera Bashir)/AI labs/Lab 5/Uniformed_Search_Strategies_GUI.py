import tkinter as tk  # Import the tkinter library for GUI
from tkinter import ttk, messagebox  # Import specific modules from tkinter
from queue import Queue  # Import the Queue class
import heapq  # Import heapq module for priority queue implementation
from collections import deque  # Import deque from collections module
import random  # Import random module for random exploration

class UniformedSearchGUI:
    def __init__(self, master):
        # Initialize the GUI
        self.master = master
        self.master.title("Uniformed Search Strategies")  # Set the title of the GUI window
        self.graph = {}  # Initialize an empty dictionary for storing graph information

        self.canvas = tk.Canvas(self.master, width=400, height=50)  # Create a canvas widget
        self.canvas.pack()  # Pack the canvas widget into the GUI window

        self.create_widgets()  # Call the function to create GUI widgets

    def create_widgets(self):
        # Create nodes entry and label
        self.lbl_nodes = ttk.Label(self.master, text="Nodes (comma-separated):")  # Create a label widget
        self.lbl_nodes.pack()  

        self.nodes_entry = ttk.Entry(self.master)  # Create an entry widget for nodes
        self.nodes_entry.pack() 

        # Create edges entry and label
        self.lbl_edges = ttk.Label(self.master, text="Edges (comma-separated, from-to-cost):")  # Create a label widget
        self.lbl_edges.pack()  

        self.edges_entry = ttk.Entry(self.master)  # Create an entry widget for edges
        self.edges_entry.pack()

        # Create start node entry and label
        self.lbl_start_node = ttk.Label(self.master, text="Start Node:")  # Create a label widget
        self.lbl_start_node.pack() 

        self.start_node_entry = ttk.Entry(self.master)  # Create an entry widget for start node
        self.start_node_entry.pack() 

        # Create goal node entry and label
        self.lbl_goal_node = ttk.Label(self.master, text="Goal Node:")  # Create a label widget
        self.lbl_goal_node.pack()  

        self.goal_node_entry = ttk.Entry(self.master)  # Create an entry widget for goal node
        self.goal_node_entry.pack()  

        # Create maximum steps entry and label
        self.lbl_max_steps = ttk.Label(self.master, text="Maximum Steps:")  # Create a label widget
        self.lbl_max_steps.pack()  

        self.max_steps_entry = ttk.Entry(self.master)  # Create an entry widget for maximum steps
        self.max_steps_entry.pack()  

        # Frame for search algorithm buttons
        self.search_algo_frame = ttk.Frame(self.master)  
        self.search_algo_frame.pack(side=tk.TOP, padx=10, pady=10)  

        # Buttons for various search algorithms
        self.btn_bfs = ttk.Button(self.search_algo_frame, text="Breadth-First Search (BFS)", command=self.breadth_first_search) 
        self.btn_bfs.pack(side=tk.LEFT, padx=5, pady=5)  

        self.btn_ucs = ttk.Button(self.search_algo_frame, text="Uniform Cost Search (UCS)", command=self.uniform_cost_search)  
        self.btn_ucs.pack(side=tk.LEFT, padx=5, pady=5)  

        self.btn_dfs = ttk.Button(self.search_algo_frame, text="Depth-First Search (DFS)", command=self.depth_first_search)  
        self.btn_dfs.pack(side=tk.LEFT, padx=5, pady=5) 

        self.btn_iddfs = ttk.Button(self.search_algo_frame, text="Iterative Deepening DFS (IDDFS)", command=self.iterative_deepening_dfs)  
        self.btn_iddfs.pack(side=tk.LEFT, padx=5, pady=5)  

        self.btn_random = ttk.Button(self.search_algo_frame, text="Random Explore", command=self.random_explore) 
        self.btn_random.pack(side=tk.LEFT, padx=5, pady=5)  
        
        self.btn_close_search = ttk.Button(self.search_algo_frame, text="Close Search", command=self.close_search)
        self.btn_close_search.pack(side=tk.LEFT, padx=5, pady=5)

        self.btn_open_search = ttk.Button(self.search_algo_frame, text="Open Search", command=self.open_search)
        self.btn_open_search.pack(side=tk.LEFT, padx=5, pady=5)

        # Configure frames appearance
        self.configure_frames()  # Call the function to configure frame appearance

    def configure_frames(self):
        # Configure search algorithm frame appearance
        self.search_algo_frame.configure(relief=tk.RIDGE, borderwidth=2, style="SearchAlgo.TFrame")

        # Define a custom style for the frame
        self.master.style = ttk.Style()  
        self.master.style.configure("SearchAlgo.TFrame", background="light grey", padx=10, pady=10)  

    def create_graph(self):
        nodes = self.nodes_entry.get().split(',')  # Get nodes input and split by comma
        edges = self.edges_entry.get().split(',')  # Get edges input and split by comma

        for node in nodes:  # Iterate over nodes
            self.graph[node.strip()] = {}  # Add node to graph dictionary

        for edge in edges:  # Iterate over edges
            from_node, to_node, cost = edge.strip().split('-')  # Split edge by '-'
            self.graph[from_node][to_node] = int(cost)  
            self.graph[to_node][from_node] = int(cost)  

    def breadth_first_search(self):
        # Breadth-First Search (BFS) algorithm
        self.create_graph()  
        start_node = self.start_node_entry.get() 
        goal_node = self.goal_node_entry.get()  
        path = self.bfs(start_node, goal_node)  
        self.show_result("BFS Result", start_node, goal_node, path)  

    def bfs(self, start, goal):
        # Breadth-First Search (BFS) algorithm implementation
        visited = set()  
        queue = deque([(start, [])]) 

        while queue:  
            current, path = queue.popleft()  
            if current == goal:   
                return path + [current] 
            if current not in visited:  
                visited.add(current)  
                for neighbor, _ in self.graph.get(current, {}).items():  
                    if neighbor not in visited:  
                        queue.append((neighbor, path + [current]))  

        return None  

    def uniform_cost_search(self):
        # Uniform Cost Search (UCS) algorithm
        self.create_graph()  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = self.ucs(start_node, goal_node)  
        self.show_result("UCS Result", start_node, goal_node, path) 

    def ucs(self, start, goal):
        # Uniform Cost Search (UCS) algorithm implementation
        visited = set()  
        priority_queue = [(0, start, [])]  

        while priority_queue:  
            cost, current, path = heapq.heappop(priority_queue)  
            if current == goal:  
                return path + [(current, cost)]  
            if current not in visited:  
                visited.add(current)  
                for neighbor, edge_cost in self.graph.get(current, {}).items():
                    if neighbor not in visited: 
                        heapq.heappush(priority_queue, (cost + edge_cost, neighbor, path + [(current, cost)]))  

        return None  

    def depth_first_search(self):
        # Depth-First Search (DFS) algorithm
        self.create_graph()  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = self.dfs(start_node, goal_node)  
        self.show_result("DFS Result", start_node, goal_node, path)  

    def dfs(self, start, goal):
        # Depth-First Search (DFS) algorithm implementation
        visited = set()  
        stack = [(start, [])]  

        while stack: 
            current, path = stack.pop() 
            if current == goal:  
                return path + [current]  
            if current not in visited:  
                visited.add(current)  
                for neighbor, _ in self.graph.get(current, {}).items():  
                    if neighbor not in visited:  
                        stack.append((neighbor, path + [current])) 

        return None   

    def iterative_deepening_dfs(self):
        # Iterative Deepening Depth-First Search (IDDFS) algorithm
        self.create_graph()  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = self.iddfs(start_node, goal_node)  
        self.show_result("IDDFS Result", start_node, goal_node, path)  

    def iddfs(self, start, goal):
        # Iterative Deepening Depth-First Search (IDDFS) algorithm implementation
        depth_limit = 0 
        while True:  
            result = self.dls(start, goal, depth_limit) 
            if result is not None:  
                return result  
            depth_limit += 1  

    def dls(self, node, goal, depth_limit):
        # Depth-Limited Search (DLS) algorithm
        if node == goal:  
            return [node]  
        elif depth_limit == 0:  
            return None  
        elif depth_limit > 0:  
            for neighbor, _ in self.graph.get(node, {}).items():  
                result = self.dls(neighbor, goal, depth_limit - 1) 
                if result is not None:  
                    return [node] + result  
            return None  

    def random_explore(self):
        # Random Exploration algorithm
        self.create_graph()  
        start_node = self.start_node_entry.get()  
        max_steps = int(self.max_steps_entry.get())  
        path = self.random_explore_util(start_node, max_steps)  
        if path:  
            messagebox.showinfo("Random Exploration Result", f"Random exploration from {start_node} with max steps {max_steps}: {path}")  
        else: 
            messagebox.showwarning("Random Exploration Result", f"No exploration possible from {start_node} within {max_steps} steps") 

    def random_explore_util(self, start_node, max_steps):
        # Random Exploration algorithm implementation
        current_node = start_node
        steps = 0  
        path = [current_node]  

        while steps < max_steps and current_node != self.goal_node_entry.get():
            neighbors = list(self.graph.get(current_node, {}).keys()) 
            if not neighbors:  
                break  
            current_node = random.choice(neighbors) 
            path.append(current_node) 
            steps += 1

        return path  
    
    def close_search(self):
        self.create_graph()
        start_node = self.start_node_entry.get()
        goal_node = self.goal_node_entry.get()
        path = self.dfs(start_node, goal_node)
        if path:
            messagebox.showinfo("Close Search Result", f"Path from {start_node} to {goal_node}: {path}")
        else:
            messagebox.showwarning("Close Search Result", f"No path found from {start_node} to {goal_node}")

    def open_search(self):
        self.create_graph()
        start_node = self.start_node_entry.get()
        goal_node = self.goal_node_entry.get()
        depth_limit = int(self.max_steps_entry.get())
        path = self.dls(start_node, goal_node, depth_limit)
        if path:
            messagebox.showinfo("Open Search Result", f"Path from {start_node} to {goal_node}: {path}")
        else:
            messagebox.showwarning("Open Search Result", f"No path found from {start_node} to {goal_node} within depth limit {depth_limit}")

    def dls(self, node, goal, depth_limit):
        if node == goal:
            return [node]
        elif depth_limit == 0:
            return None
        elif depth_limit > 0:
            for neighbor, _ in self.graph.get(node, {}).items():
                result = self.dls(neighbor, goal, depth_limit - 1)
                if result is not None:
                    return [node] + result
            return None

    def show_result(self, title, start, goal, path):
        # Function to display search results
        if path: 
            messagebox.showinfo(title, f"Path from {start} to {goal}: {path}") 
        else: 
            messagebox.showwarning(title, f"No path found from {start} to {goal}")

# Main function to run the GUI
def main():
    root = tk.Tk() 
    app = UniformedSearchGUI(root)  
    root.mainloop()  

if __name__ == "__main__":
    main() 