#include <iostream>
#include <climits> // Include the climits library to access integer type limits.
#include <unordered_set>

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

// Function to insert a new edge between two vertices with a weight (for an undirected graph)
void Insert_Edge(char from_Value, char to_Value, int weight)
{
    // Add the edge from 'from_Value' to 'to_Value'
    struct Vertex *from_Vertex = V_start;
    while (from_Vertex != NULL)
    {
        if (from_Vertex->data == from_Value)
        {
            Edge *E_temp = new Edge();
            E_temp->E_Data = to_Value;
            E_temp->weight = weight;
            E_temp->next = NULL;

            if (from_Vertex->E_start == NULL)
            {
                from_Vertex->E_start = E_temp;
            }
            else
            {
                Edge *E_curr = from_Vertex->E_start;
                while (E_curr->next != NULL)
                {
                    E_curr = E_curr->next;
                }
                E_curr->next = E_temp;
            }
            break;
        }
        from_Vertex = from_Vertex->next;
    }

    // Add the edge from 'to_Value' to 'from_Value' (for the undirected graph)
    struct Vertex *to_Vertex = V_start;
    while (to_Vertex != NULL)
    {
        if (to_Vertex->data == to_Value)
        {
            Edge *E_temp = new Edge();
            E_temp->E_Data = from_Value;
            E_temp->weight = weight;
            E_temp->next = NULL;

            if (to_Vertex->E_start == NULL)
            {
                to_Vertex->E_start = E_temp;
            }
            else
            {
                Edge *E_curr = to_Vertex->E_start;
                while (E_curr->next != NULL)
                {
                    E_curr = E_curr->next;
                }
                E_curr->next = E_temp;
            }
            break;
        }
        to_Vertex = to_Vertex->next;
    }
}

// Function to print the adjacency list, including weights
void print_Adjacency_List()
{
    Vertex *V_curr = V_start;
    while (V_curr != NULL)
    {
        std::cout << V_curr->data << " -> ";
        Edge *E_curr = V_curr->E_start;
        while (E_curr != NULL)
        {
            std::cout << E_curr->E_Data << "(" << E_curr->weight << ") "; // Print the destination vertex and edge weight
            E_curr = E_curr->next;
        }
        std::cout << std::endl;
        V_curr = V_curr->next;
    }
}

// Function to implement Prim's algorithm for finding a minimum spanning tree
void Prim(char start_Vertex)
{
    int n = size;                              // Get the total number of vertices
    bool visited[n] = {false};                 // Initialize an array to track visited vertices
    int weight[n];                             // Initialize an array to store weights of vertices
    char parent[n];                            // Initialize an array to store parent vertices
    std::unordered_set<char> includedVertices; // Track vertices included in the minimum spanning tree

    // Initialize weight and parent arrays
    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX; // Set initial weights to infinity
        parent[i] = '\0';    // Initialize parent vertices to null character
    }

    int start_Idx = start_Vertex - 'A'; // Convert the start_Vertex character to an index

    weight[start_Idx] = 0; // Set the weight of the starting vertex to 0

    for (int i = 0; i < n; i++)
    {
        int min_Weight = INT_MAX; // Initialize the minimum weight
        int min_Vertex = -1;      // Initialize the index of the minimum weight vertex

        // Find the minimum weight vertex that has not been visited
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && weight[v] < min_Weight)
            {
                min_Weight = weight[v]; // Update minimum weight
                min_Vertex = v;         // Update index of the minimum weight vertex
            }
        }

        if (min_Vertex == -1)
        {
            break; // If no connected component, exit the loop
        }

        visited[min_Vertex] = true; // Mark the minimum weight vertex as visited

        Vertex *from_Vertex = V_start;
        while (from_Vertex != NULL)
        {
            if (from_Vertex->data - 'A' == min_Vertex)
            {
                Edge *E_curr = from_Vertex->E_start;
                while (E_curr != NULL)
                {
                    int to_Idx = E_curr->E_Data - 'A';

                    if (!visited[to_Idx] && E_curr->weight < weight[to_Idx])
                    {
                        // Check for cycle by verifying if the 'to' vertex is already included in the minimum spanning tree
                        if (includedVertices.find(E_curr->E_Data) == includedVertices.end())
                        {
                            weight[to_Idx] = E_curr->weight;    // Update the weight of adjacent vertices
                            parent[to_Idx] = from_Vertex->data; // Set the parent of the adjacent vertex
                        }
                    }

                    E_curr = E_curr->next;
                }
                break;
            }
            from_Vertex = from_Vertex->next;
        }

        // Mark the 'to' vertex as included in the minimum spanning tree
        includedVertices.insert(char('A' + min_Vertex));
    }

    int total_Weight = 0; // Initialize the total weight of the minimum spanning tree

    // Print the edges of the minimum spanning tree
    for (int i = 0; i < n; i++)
    {
        if (i != start_Idx)
        {
            std::cout << parent[i] << " - " << char('A' + i) << " ( Weight: " << weight[i] << ")\n";
            total_Weight += weight[i]; // Calculate the total weight of the minimum spanning tree
        }
    }

    // Print the total weight of the minimum spanning tree
    std::cout << "Sum of weights in the minimum spanning tree: " << total_Weight << std::endl;
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

    Prim('A');

    return 0;
}
