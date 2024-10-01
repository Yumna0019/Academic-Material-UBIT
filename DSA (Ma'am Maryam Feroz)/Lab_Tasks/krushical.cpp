#include <iostream>
#include <climits>
#include <set>

// Define a structure for an edge in the graph
struct Edge
{
    char E_Data; // Data of the target vertex of the edge
    char to;     // Data of the source vertex of the edge (change this for an undirected graph)
    int weight;  // Weight of the edge
    Edge *next;  // Pointer to the next edge
};

// Define a structure for a vertex in the graph
struct Vertex
{
    char data;     // Data of the vertex
    Vertex *next;  // Pointer to the next vertex
    Edge *E_start; // Pointer to the first edge starting from this vertex
};

struct Vertex *V_start = NULL; // Initialize the start of the vertex list
int size = 0;                  // Initialize the size of the graph

// Function to insert a new vertex into the graph
void Insert_Vertex(char value)
{
    Vertex *V_temp = new Vertex(); // Create a new vertex
    V_temp->data = value;          // Set the data of the new vertex
    V_temp->next = NULL;
    V_temp->E_start = NULL; // Initialize the edge list of the new vertex

    if (V_start == NULL)
    {
        V_start = V_temp; // If the graph is empty, set the new vertex as the start
    }
    else
    {
        struct Vertex *V_curr = V_start;
        while (V_curr->next != NULL)
        {
            V_curr = V_curr->next; // Find the last vertex in the list
        }
        V_curr->next = V_temp; // Add the new vertex to the end of the list
    }
    size++; // Increment the size of the graph
}

// Function to insert a new edge into the graph
void Insert_Edge(char from_Value, char to_Value, int weight)
{
    struct Vertex *from_Vertex = V_start;
    while (from_Vertex != NULL)
    {
        if (from_Vertex->data == from_Value) // Find the source vertex of the edge
        {
            Edge *E_temp = new Edge(); // Create a new edge
            E_temp->E_Data = to_Value; // Set the target vertex's data
            E_temp->to = from_Value;   // Set the source vertex's data (change for an undirected graph)
            E_temp->weight = weight;   // Set the weight of the edge
            E_temp->next = NULL;

            if (from_Vertex->E_start == NULL)
            {
                from_Vertex->E_start = E_temp; // If the source vertex has no edges, set the new edge as the first
            }
            else
            {
                Edge *E_curr = from_Vertex->E_start;
                while (E_curr->next != NULL)
                {
                    E_curr = E_curr->next; // Find the last edge in the source vertex's edge list
                }
                E_curr->next = E_temp; // Add the new edge to the end of the edge list
            }
            return;
        }
        from_Vertex = from_Vertex->next; // Move to the next vertex in the list
    }
}

// Function to print the adjacency list representation of the graph
void print_Adjacency_List()
{
    Vertex *V_curr = V_start;
    while (V_curr != NULL)
    {
        std::cout << V_curr->data << " -> ";
        Edge *E_curr = V_curr->E_start;
        while (E_curr != NULL)
        {
            std::cout << E_curr->E_Data << "(" << E_curr->weight << ") "; // Print the edge data and weight
            E_curr = E_curr->next;                                        // Move to the next edge
        }
        std::cout << std::endl;
        V_curr = V_curr->next; // Move to the next vertex in the list
    }
}

// Function to find the minimum spanning tree of the graph using Kruskal's algorithm
void Kruskal()
{
    int n = size; // Get the number of vertices in the graph

    Edge Kruskal_Edges[n * (n - 1) / 2]; // Create an array to store all edges

    int edge_Index = 0;

    // Iterate through the vertices to populate the array with edges
    for (Vertex *V_curr = V_start; V_curr != NULL; V_curr = V_curr->next)
    {
        char from = V_curr->data; // Get the source vertex's data
        Edge *E_curr = V_curr->E_start;
        while (E_curr != NULL)
        {
            char to = E_curr->E_Data;    // Get the target vertex's data
            int weight = E_curr->weight; // Get the weight of the edge
            Kruskal_Edges[edge_Index].E_Data = from;   // Set the source vertex's data for this edge.
            Kruskal_Edges[edge_Index].to = to;        // Set the target vertex's data for this edge.
            Kruskal_Edges[edge_Index].weight = weight; // Set the weight of this edge.

            edge_Index++;
            E_curr = E_curr->next;
        }
    }

    // Sort the edges by weight in non-decreasing order
    for (int i = 0; i < edge_Index - 1; i++)
    {
        for (int j = 0; j < edge_Index - i - 1; j++)
        {
            if (Kruskal_Edges[j].weight > Kruskal_Edges[j + 1].weight)
            {
                Edge temp = Kruskal_Edges[j];
                Kruskal_Edges[j] = Kruskal_Edges[j + 1];
                Kruskal_Edges[j + 1] = temp;
            }
        }
    }

    int total_Weight = 0;

    std::set<char> includedVertices; // Set to keep track of included vertices

    // Find the minimum spanning tree edges and calculate the total weight
    for (int i = 0; i < edge_Index; i++)
    {
        char from = Kruskal_Edges[i].E_Data;  // Get the source vertex's data
        int weight = Kruskal_Edges[i].weight; // Get the weight of the edge
        char to = Kruskal_Edges[i].to;        // Get the target vertex's data

        // If either the source or target vertex is not included, include them in the minimum spanning tree
        if (includedVertices.find(from) == includedVertices.end() || includedVertices.find(to) == includedVertices.end())
        {
            std::cout << from << " - " << to << " (Weight: " << weight << ")\n"; // Print the edge
            total_Weight += weight;        // Accumulate the edge's weight to the total weight of the minimum spanning tree.
            includedVertices.insert(from);  // Mark the source vertex 'from' as included in the minimum spanning tree.
            includedVertices.insert(to);    // Mark the target vertex 'to' as included in the minimum spanning tree.
        }
    }

    std::cout << "Total weight of the minimum spanning tree: " << total_Weight << std::endl;
}

int main()
{
    // Insert vertices into the graph
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

    // Insert edges into the graph
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

    print_Adjacency_List();                                         // Print the adjacency list of the graph
    std::cout << "Total number of vertices: " << size << std::endl; // Print the total number of vertices

    Kruskal(); // Find and print the minimum spanning tree using Kruskal's algorithm

    return 0;
}
