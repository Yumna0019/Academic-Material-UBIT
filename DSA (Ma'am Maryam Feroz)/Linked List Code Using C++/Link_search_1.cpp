#include <iostream>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node
{
    int id;
    int marks;
    struct Node *next = NULL; // Initialize the 'next' pointer to NULL
};

// Initialize a pointer to the start of the linked list
struct Node *start = NULL; // Initialize the 'start' pointer to NULL

// Function to insert a new node into the linked list
void insert()
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    // Taking input of id and marks from the user
    std::cout << "Enter the id: ";
    std::cin >> temp->id;
    std::cout << "Enter the marks: ";
    std::cin >> temp->marks;

    temp->next = NULL; // Set the 'next' pointer of the new node to NULL

    // Check if the linked list is empty
    if (start == NULL)
    {
        start = temp; // If empty, set the 'start' pointer to the new node
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

    // Print each node's id
    while (curr != NULL) // Traverse until the end of the list
    {
        std::cout << curr->id << " "; // Print the current node's id
        curr = curr->next;            // Move 'curr' to the next node
    }
}

// Function to search for a specific id in the linked list
bool search()
{
    struct Node *curr = start; // Create a pointer 'curr' to traverse the list
    int tosearch;
    std::cout << "Enter the id you want to search: " << std::endl;
    std::cin >> tosearch; // Read the id to be searched

    while (curr != NULL) // Traverse until the end of the list
    {
        if (tosearch == curr->id) // Check if the current node's id matches the id to search
        {
            // std::cout << "Value is found." << std::endl;
            return true; // Return true if the value is found and exit the function
            break;
        }
        curr = curr->next; // Move 'curr' to the next node
    }

    // std::cout << "Value is not found." << std::endl;
    return false; // Return false if the value is not found
}
void Searchprint()
{
    if (search())
    {
        std::cout << "value found";
    }
    else
    {
        std::cout << "value not found";
    }
}

int main()
{
    insert(); // Insert the first element
    insert(); // Insert the second element
    insert(); // Insert the third element

    std::cout << "List of id elements: " << std::endl;
    print(); // Print the list of id elements
    std::cout << std::endl;
    Searchprint(); // Search for a specific id and print the result
    std::cout << std::endl;

    return 0;
}
