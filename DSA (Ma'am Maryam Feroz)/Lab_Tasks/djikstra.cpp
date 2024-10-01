#include <iostream>
#include <climits> // Include the climits library to access integer type limits.

// Define a structure for an edge in the adjacency list
struct Edge
{
    char E_Data; // Destination vertex of the edge
    int weight;  // Weight of the edge
    Edge *next;  // Pointer to the next edge in the list
};

// Define a structure for a vertex in the adjacency list
struct Vertex
{
    char data;     // Data associated with the vertex
    Vertex *next;  // Pointer to the next vertex in the list
    Edge *E_start; // Pointer to the start of the list of edges
};

struct Vertex *V_start = NULL; // Initialize the start of the vertex list to null
int size = 0;                  // Initialize the number of vertices to 0

// Function to insert a new vertex into the adjacency list
void Insert_Vertex(char value)
{
    // Create a new vertex with the given data
    Vertex *V_temp = new Vertex();
    V_temp->data = value;
    V_temp->next = NULL;    // Initialize the next pointer to null
    V_temp->E_start = NULL; // Initialize the list of edges to null

    if (V_start == NULL)
    {
        V_start = V_temp; // If the list is empty, set the new vertex as the start
    }
    else
    {
        struct Vertex *V_curr = V_start;
        while (V_curr->next != NULL)
        {
            V_curr = V_curr->next; // Traverse the list to find the last vertex
        }
        V_curr->next = V_temp; // Add the new vertex at the end of the list
    }
    size++; // Increment the count of vertices
}

// Function to insert a new edge for an undirected graph
void Insert_Edge(char vertex1, char vertex2, int weight)
{
    // Create an edge from vertex1 to vertex2
    struct Vertex *v1 = V_start;
    while (v1 != NULL)
    {
        if (v1->data == vertex1)
        {
            Edge *E_temp = new Edge();
            E_temp->E_Data = vertex2;
            E_temp->weight = weight;
            E_temp->next = NULL;

            if (v1->E_start == NULL)
            {
                v1->E_start = E_temp;
            }
            else
            {
                Edge *E_curr = v1->E_start;
                while (E_curr->next != NULL)
                {
                    E_curr = E_curr->next;
                }
                E_curr->next = E_temp;
            }
            break;
        }
        v1 = v1->next;
    }

    // Create an edge from vertex2 to vertex1
    struct Vertex *v2 = V_start;
    while (v2 != NULL)
    {
        if (v2->data == vertex2)
        {
            Edge *E_temp = new Edge();
            E_temp->E_Data = vertex1;
            E_temp->weight = weight;
            E_temp->next = NULL;

            if (v2->E_start == NULL)
            {
                v2->E_start = E_temp;
            }
            else
            {
                Edge *E_curr = v2->E_start;
                while (E_curr->next != NULL)
                {
                    E_curr = E_curr->next;
                }
                E_curr->next = E_temp;
            }
            break;
        }
        v2 = v2->next;
    }
}

// Function to print the adjacency list, including weights
void print_Adjacency_List()
{
    struct Vertex *V_curr = V_start;
    while (V_curr != NULL)
    {
        std::cout << V_curr->data << " -> ";
        struct Edge *E_curr = V_curr->E_start;
        while (E_curr != NULL)
        {
            std::cout << E_curr->E_Data << "(" << E_curr->weight << ") ";
            E_curr = E_curr->next;
        }
        std::cout << std::endl;
        V_curr = V_curr->next;
    }
}
// Function to implement Dijkstra's algorithm for finding the shortest path
void Dijkstra(char start_Vertex)
{
    int n = size;              // Get the number of vertices in the graph
    int dist[n];               // Array to store the shortest distance from the start vertex to all other vertices
    bool visited[n] = {false}; // Array to keep track of visited vertices

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX; // Initialize all distances to infinity
    }

    int start_Idx = start_Vertex - 'A'; // Convert the starting vertex character to an index (e.g., 'A' to 0)
    dist[start_Idx] = 0;                // Set the distance to the start vertex as 0

    for (int i = 0; i < n - 1; i++)
    {
        int min_Dist = INT_MAX; // Initialize the minimum distance to infinity
        int min_Vertex = -1;    // Initialize the minimum distance vertex to -1

        // Find the vertex with the minimum distance that has not been visited
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] < min_Dist)
            {
                min_Dist = dist[v]; // Update the minimum distance
                min_Vertex = v;     // Update the vertex with the minimum distance
            }
        }

        if (min_Vertex == -1)
        {
            break; // If there are no more unvisited vertices with finite distance, exit the loop
        }

        visited[min_Vertex] = true; // Mark the vertex as visited

        Vertex *from_Vertex = V_start;
        while (from_Vertex != NULL)
        {
            if (from_Vertex->data - 'A' == min_Vertex)
            {
                Edge *E_curr = from_Vertex->E_start;
                while (E_curr != NULL)
                {
                    int to_Idx = E_curr->E_Data - 'A';                // Convert the destination vertex character to an index
                    int new_Dist = dist[min_Vertex] + E_curr->weight; // Calculate the new distance

                    if (!visited[to_Idx] && new_Dist < dist[to_Idx])
                    {
                        dist[to_Idx] = new_Dist; // Update the distance if it's shorter
                    }
                    E_curr = E_curr->next; // Move to the next edge
                }
                break; // Break the loop once the correct from_Vertex is found
            }
            from_Vertex = from_Vertex->next; // Move to the next vertex in the adjacency list
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != start_Idx)
        {
            std::cout << "Shortest distance from " << start_Vertex << " to " << char('A' + i) << " is: " << dist[i] << std::endl;
        }
    }
}

int main()
{
    // Insert vertices into the adjacency list
    Insert_Vertex('A');
    Insert_Vertex('B');
    Insert_Vertex('C');
    Insert_Vertex('D');
    Insert_Vertex('E');
    Insert_Vertex('F');
    Insert_Vertex('G');
    Insert_Vertex('H');
    Insert_Vertex('I');
    Insert_Vertex('J');
    Insert_Vertex('K');
    Insert_Vertex('L');

    // Insert edges to create the undirected graph
    Insert_Edge('A', 'B', 2);
    Insert_Edge('A', 'D', 2);
    Insert_Edge('A', 'C', 3);
    Insert_Edge('B', 'H', 5);
    Insert_Edge('C', 'G', 1);
    Insert_Edge('D', 'F', 3);
    Insert_Edge('D', 'E', 2);
    Insert_Edge('E', 'F', 2);
    Insert_Edge('E', 'J', 6);
    Insert_Edge('G', 'I', 2);
    Insert_Edge('G', 'J', 2);
    Insert_Edge('H', 'G', 2);
    Insert_Edge('I', 'L', 1);
    Insert_Edge('I', 'J', 1);
    Insert_Edge('J', 'K', 5);

    print_Adjacency_List();
    std::cout << "Total number of vertices: " << size << std::endl;

    Dijkstra('A');

    return 0;
}
