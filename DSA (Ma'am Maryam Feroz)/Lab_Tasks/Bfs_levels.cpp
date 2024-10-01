#include <iostream>
#include <queue>
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

// Breadth-First Search (BFS) function
void bfs(char startVertex)
{
    std::queue<Vertex*> q;  // Create a queue to perform BFS

    // Initialize the 'visited' flag for all vertices to false
    for (Vertex& v : graph)
    {
        v.visited = false;
    }

    // Find and mark the 'startVertex' as visited, then push it into the queue
    for (Vertex& v : graph)
    {
        if (v.data == startVertex)
        {
            q.push(&v);
            v.visited = true;
            break;
        }
    }

    // Perform BFS
    std::cout << "BFS starting from vertex " << startVertex << ": ";
    while (!q.empty())
    {
        Vertex* currentVertex = q.front();  // Get the front vertex from the queue
        q.pop();                            // Remove the current vertex from the queue
        std::cout << currentVertex->data << " ";  // Output the current vertex's data

        // Visit neighbors of the current vertex
        for (Vertex* neighbor : currentVertex->neighbors)
        {
            if (!neighbor->visited)
            {
                q.push(neighbor);         // Push unvisited neighbors into the queue
                neighbor->visited = true; // Mark them as visited
            }
        }
    }
    std::cout << std::endl;
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

    // Perform BFS starting from vertex 'A'
    bfs('A');

    return 0;
}
