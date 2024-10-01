#include <iostream>

// Define a structure for an edge in the adjacency list
struct Edge
{
    char to_Vertex;
    Edge *next;
};

// Define a structure for a vertex in the adjacency list
struct Vertex
{
    char data;
    Vertex *next;
    Edge *E_start; // Pointer to the start of the linked list of edges
};

struct Vertex *V_start = NULL; // Initialize the start of the adjacency list as NULL

// Function to insert a new vertex into the adjacency list
void Insert_Vertex(char value)
{
    struct Vertex *V_temp = new Vertex();
    V_temp->data = value;
    V_temp->next = NULL;
    V_temp->E_start = NULL; // Initialize the edge linked list for this vertex

    if (V_start == NULL)
    {
        V_start = V_temp; // If the adjacency list is empty, set the new vertex as the start
    }
    else
    {
        struct Vertex *V_curr = V_start;
        while (V_curr->next != NULL)
        {
            V_curr = V_curr->next;
        }
        V_curr->next = V_temp; // Traverse to the end of the list and link the new vertex
    }
}

// Function to insert a new edge from 'from_Value' to 'to_Value'
void Insert_Edge(char from_Value, char to_Value)
{
    struct Vertex *from_Vertex = V_start;
    while (from_Vertex != NULL)
    {
        if (from_Vertex->data == from_Value)
        {
            struct Edge *E_temp = new Edge();
            E_temp->to_Vertex = to_Value;
            E_temp->next = NULL;

            if (from_Vertex->E_start == NULL)
            {
                from_Vertex->E_start = E_temp; // If there are no edges, set the new edge as the start
            }
            else
            {
                struct Edge *E_curr = from_Vertex->E_start;
                while (E_curr->next != NULL)
                {
                    E_curr = E_curr->next;
                }
                E_curr->next = E_temp; // Traverse to the end of the edge list and link the new edge
            }
            return;
        }
        from_Vertex = from_Vertex->next;
    }
}

// Function to print the adjacency list
void print_Adjacency_List()
{
    struct Vertex *V_curr = V_start;
    while (V_curr != NULL)
    {
        std::cout << V_curr->data << " -> ";
        struct Edge *E_curr = V_curr->E_start;
        while (E_curr != NULL)
        {
            std::cout << E_curr->to_Vertex << " ";
            E_curr = E_curr->next;
        }
        std::cout << std::endl;
        V_curr = V_curr->next;
    }
}

int no_of_edges_Undirected_Degree(char data)
{
    int count = 0;
    struct Vertex *V_curr = V_start;
    while (V_curr != NULL)
    {
        if (V_curr->data == data)
        {
            struct Edge *E_curr = V_curr->E_start;
            while (E_curr != NULL)
            {
                count++;
                E_curr = E_curr->next;
            }
        }
        V_curr = V_curr->next;
    }

    return count;
}

int main()
{
    char v;
    // Insert vertices into the adjacency list
    Insert_Vertex('A');
    Insert_Vertex('B');
    Insert_Vertex('C');
    Insert_Vertex('D');
    Insert_Vertex('E');
    Insert_Vertex('F');
    Insert_Vertex('G');

    // Insert edges to create the undirected graph
    Insert_Edge('A', 'B');
    Insert_Edge('A', 'D');
    Insert_Edge('A', 'F');
    Insert_Edge('A', 'C');
    Insert_Edge('B', 'A');
    Insert_Edge('B', 'C');
    Insert_Edge('B', 'E');
    Insert_Edge('C', 'B');
    Insert_Edge('C', 'A');
    Insert_Edge('C', 'F');
    Insert_Edge('D', 'A');
    Insert_Edge('D', 'G');
    Insert_Edge('E', 'B');
    Insert_Edge('E', 'C');
    Insert_Edge('E', 'G');
    Insert_Edge('F', 'A');
    Insert_Edge('G', 'D');
    Insert_Edge('G', 'E');

    // Print the adjacency list to visualize the graph
    print_Adjacency_List();

    std::cout << "Enter the vertex of which the degree is to be known: ";
    std::cin >> v;
    int a = no_of_edges_Undirected_Degree(v);
    std::cout << "The no. of edges are: " << a;
    return 0;
}
