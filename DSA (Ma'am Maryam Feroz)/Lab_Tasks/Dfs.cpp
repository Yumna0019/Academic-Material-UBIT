#include <iostream>
#include <list>

// Define a structure for a Vertex
struct Vertex
{
    char data;             // Data associated with the vertex
    std::list<Vertex*> neighbors;  // List of neighboring vertices
    bool visited;          // Flag to mark if the vertex has been visited
};

std::list<Vertex> graph;  // Create a list to store vertices

// Function to add a new vertex to the graph
void addVertex(char data)
{
    Vertex v;            // Create a new vertex
    v.data = data;       // Assign data to the vertex
    v.visited = false;   // Initialize visited flag to false
    graph.push_back(v);  // Add the vertex to the graph list
}

// Function to add an edge between two vertices
void addEdge(char from, char to)
{
    Vertex* fromVertex = nullptr;
    Vertex* toVertex = nullptr;

    // Find the 'from' and 'to' vertices in the graph
    for (Vertex& v : graph)
    {
        if (v.data == from)
            fromVertex = &v;
        if (v.data == to)
            toVertex = &v;
    }

    // If both 'from' and 'to' vertices exist, add them as neighbors
    if (fromVertex && toVertex)
    {
        fromVertex->neighbors.push_back(toVertex);  // Add 'to' as a neighbor of 'from'
        toVertex->neighbors.push_back(fromVertex);  // For an undirected graph, add 'from' as a neighbor of 'to'
    }
}

// Depth-First Search (DFS) function using recursion
void dfs(char currentVertex)
{
    for (Vertex& v : graph)
    {
        if (v.data == currentVertex)
        {
            v.visited = true;  // Mark the current vertex as visited
            std::cout << currentVertex << " ";  // Output the data of the current vertex

            for (Vertex* neighbor : v.neighbors)
            {
                if (!neighbor->visited)
                {
                    dfs(neighbor->data);  // Recursively visit unvisited neighbors
                }
            }
            return;
        }
    }
}

int main()
{
    // Add vertices to the graph
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addVertex('E');
    addVertex('F');
    addVertex('G');

    // Add edges to create the undirected graph
    addEdge('A', 'B');
    addEdge('A', 'D');
    addEdge('A', 'F');
    addEdge('A', 'C');
    addEdge('B', 'C');
    addEdge('B', 'E');
    addEdge('C', 'E');
    addEdge('D', 'G');
    addEdge('E', 'G');

    std::cout << "DFS starting from vertex A: ";
    dfs('A');  // Perform DFS starting from vertex 'A'
    std::cout << std::endl;

    return 0;
}
