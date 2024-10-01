#include <iostream>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node
{
    int add;
    struct Node *next = NULL; // Initialize the 'next' pointer to NULL
};

// Initialize a pointer to the start of the linked list
struct Node *start = NULL; // Initialize the 'start' pointer to NULL

// Function to insert a new node into the linked list
void add()
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    // Taking input from the user
    std::cout << "ADD ";
    std::cin >> temp->add;

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
        struct Node *prev = NULL;  // Create a pointer 'prev' to keep track of the previous node

        // Check if the number already exists in the list
        while (curr != NULL)
        {
            if (curr->add == temp->add)
            {
                std::cout << "Number " << temp->add << " already exists in the list. Duplicate not added." << std::endl;
                free(temp); // Free the memory of the new node
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        // If the number is not a duplicate, insert it at the end of the list
        prev->next = temp;
    }
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

    // Update the 'next' pointer to the last node to NULL
    prev->next = NULL;

    // Free the memory of the last node
    free(curr);
}

// Function to get the middle number(s) in the linked list
void GetTrump()
{
    if (start == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    struct Node *slow_ptr = start;
    struct Node *fast_ptr = start;
    struct Node *prev_slow_ptr = start;

    // Use two pointers, one moving one step at a time (slow_ptr) and the other moving two steps at a time (fast_ptr)
    // When the fast_ptr reaches the end, the slow_ptr will be at the middle for odd-sized lists
    // and just before the middle for even-sized lists
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    // Print the middle number(s)
    if (fast_ptr == NULL)
    {
        // Even-sized list, print two middle numbers
        std::cout << "Middle two numbers: " << prev_slow_ptr->add << " and " << slow_ptr->add << std::endl;
    }
    else
    {
        // Odd-sized list, print the middle number
        std::cout << "Middle number: " << slow_ptr->add << std::endl;
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
        std::cout << curr->add << " ->  "; // Print the current node's add
        curr = curr->next;                 // Move 'curr' to the next node
    }
    std::cout << "null" << std::endl;
}
int main()
{
    char choice;

    do
    {
        std::cout << "Choose an operation (A for Add, D for Delete, G for GetTrump, E for End): ";
        std::cin >> choice;

        switch (choice)
        {
        case 'A':
        case 'a':
            add();
            break;
        case 'D':
        case 'd':
            deletion();
            std::cout << "Deleted." << std::endl;
            break;
        case 'G':
        case 'g':
            GetTrump();
            break;
        case 'E':
        case 'e':
            // End the loop
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 'E' && choice != 'e');
    // Print a message before printing the linked list
    std::cout << "Now the linked list will be:" << std::endl;
    print();
    return 0;
}