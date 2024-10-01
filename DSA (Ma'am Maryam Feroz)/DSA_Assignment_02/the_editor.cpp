#include <iostream>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node
{
    int add;           // Data of the node
    struct Node *next; // Pointer to the next node
    struct Node *prev; // Pointer to the previous node
};

// Initialize a pointer to the start of the linked list
struct Node *start = NULL; // Initialize the 'start' pointer to NULL

// Initialize a cursor to NULL
struct Node *cursor = NULL; // Initialize the 'cursor' pointer to NULL

// Function to add a new node into the linked list
void add()
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    // Taking input of add and marks from the user
    std::cout << "Enter the number: ";
    std::cin >> temp->add;

    temp->next = NULL; // Set the 'next' pointer of the new node to NULL

    // Check if the linked list is empty
    if (start == NULL)
    {
        start = temp;  // If empty, set the 'start' pointer to the new node
        cursor = temp; // Set the 'cursor' pointer to the new node
        return;
    }
    else
    {
        struct Node *curr = start; // Create a pointer 'curr' to traverse the list
        while (curr->next != NULL) // Traverse to the last node
        {
            curr = curr->next; // Move 'curr' to the next node
        }
        curr->next = temp; // Set the 'next' pointer of the last node to the new node
        cursor = temp;     // Update the 'cursor' pointer to the new node
    }
}

// Function to print the elements of the linked list
void print()
{
    if (start == NULL)
    {
        std::cout << "List is empty." << std::endl;
    }
    struct Node *curr = start; // Create a pointer 'curr' to traverse the list

    // Print each node's add
    while (curr != NULL) // Traverse until the end of the list
    {
        std::cout << curr->add << " -> "; // Print the current node's add
        curr = curr->next;                // Move 'curr' to the next node
    }
    std::cout << "null" << std::endl;
}

// Function to delete the last element in the linked list
void deletion()
{
    if (start == NULL)
    {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }
    // If there's only one node in the list, delete it
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        cursor = NULL; // Set the 'cursor' to NULL as there are no nodes left
        return;
    }
    struct Node *curr = start;
    struct Node *prev = NULL;

    // Traverse the list until curr points to the last node
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    // Update the 'next' pointer of the second-to-last node to NULL
    prev->next = NULL;

    // Free the memory of the last node
    free(curr);
}

// Function to add a new node at a specified index
void add_index_number()
{
    int num;
    std::cout << "Enter index number: ";
    std::cin >> num;

    if (num < 0)
    {
        std::cout << "Index number should be non-negative." << std::endl;
        return;
    }

    // Create a new node and read data into it
    struct Node *new_node = new Node;
    std::cout << "Enter number to add at index " << num << ": ";
    std::cin >> new_node->add;

    // Insert at the beginning (index 0)
    if (num == 0)
    {
        new_node->next = start;
        new_node->prev = NULL;

        if (start != NULL)
        {
            start->prev = new_node;
        }

        start = new_node;
        return;
    }

    struct Node *ptr = start;
    int index = 0;

    // Traverse the list to find the node at the specified index
    while (ptr != NULL && index < (num - 1))
    {
        ptr = ptr->next;
        index++;
    }

    if (index == (num - 1) && ptr != NULL)
    {
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next = new_node->prev;
        ptr->next = new_node;
    }
    else
    {
        std::cout << "Index number is out of range." << std::endl;
        delete new_node; // Free the memory allocated for the new node
    }
}

// Function to delete a node at a specified index
void delete_index()
{
    int index;
    std::cout << "Enter the index number to delete: ";
    std::cin >> index;

    if (index < 0)
    {
        std::cout << "Index number should be non-negative." << std::endl;
        return;
    }

    if (start == NULL)
    {
        std::cout << "List is empty. Nothing to delete." << std::endl;
        return;
    }

    if (index == 0)
    {
        // Deleting the first node
        struct Node *temp = start;
        start = start->next;
        free(temp);
        return;
    }

    struct Node *curr = start;
    struct Node *prev = NULL;
    int current_index = 0;

    // Traverse the list to find the node at the specified index
    while (curr != NULL && current_index < index)
    {
        prev = curr;
        curr = curr->next;
        current_index++;
    }

    if (curr == NULL)
    {
        std::cout << "Index out of range. Node not found." << std::endl;
        return;
    }

    // Remove the node at the specified index
    prev->next = curr->next;
    free(curr);
}

// Function to move the cursor forward by a specified number of steps
void move_forward_steps()
{
    int num;
    std::cout << "Enter move forward steps: ";
    std::cin >> num;

    if (num < 0)
    {
        std::cout << "Invalid number of steps." << std::endl;
        return;
    }

    int index = 0;
    struct Node *curr = start;

    while (curr != NULL && index < num)
    {
        curr = curr->next;
        index++;
    }

    if (index == num && curr != NULL)
    {
        cursor = curr;
        std::cout << "Cursor moved forward by " << num << " step(s)." << std::endl;
    }
    else
    {
        std::cout << "Index number is out of range." << std::endl;
    }
}

// Function to move the cursor backward by a specified number of steps
void move_backward_steps()
{
    int num;
    std::cout << "Enter move backward steps: ";
    std::cin >> num;

    if (num < 0)
    {
        std::cout << "Invalid number of steps." << std::endl;
        return;
    }

    int index = 0;
    struct Node *curr = cursor;

    while (curr != NULL && index < num)
    {
        curr = curr->prev;
        index++;
    }

    if (index == num && curr != NULL)
    {
        cursor = curr;
        std::cout << "Cursor moved backward by " << num << " step(s)." << std::endl;
    }
    else
    {
        std::cout << "Index number is out of range." << std::endl;
    }
}

// Function to print the data of the cursor's node
void print_cursor_position()
{
    if (cursor)
    {
        std::cout << "Data of the cursor's node: " << cursor->add << std::endl;
    }
    else
    {
        std::cout << "Cursor is not pointing to any node." << std::endl;
    }
}

int main()
{
    add();
    add();
    add();
    deletion();
    std::cout << "Deleted last element." << std::endl;
    print();

    add_index_number();
    delete_index();
    print();

    move_forward_steps();
    print_cursor_position();
    move_backward_steps();
    print_cursor_position();

    return 0;
}
