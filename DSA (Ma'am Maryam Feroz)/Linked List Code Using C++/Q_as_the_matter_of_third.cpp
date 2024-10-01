#include <iostream>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};
struct Node *start = NULL; // Initialize the linked list as empty

// Function to insert data at the end of the linked list
void insert(int value)
{
    // Allocate memory for a new transaction node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = value;
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

// Function to find and print the third last element in the list
void print_Third_Last_Element()
{
    if (start == NULL)
    {
        std::cout << -1 << std::endl; // If list is empty, print -1
        return;
    }

    if (start->next == NULL || start->next->next == NULL)
    {
        std::cout << -1 << std::endl; // List has less than three elements, print -1
        return;
    }

    struct Node *current = start;
    while (current->next->next->next != NULL)
    {
        current = current->next;
    }

    std::cout << std::endl; // Print a blank line
    
    // Print the data of the third last element
    std::cout << "Third last element is: " << current->data << std::endl;
}

int main()
{
    int n, value;

    // Prompt the user to enter the number of elements
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Loop to input elements and insert them into the linked list
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Enter the elements " << i + 1 << ": ";
        std::cin >> value;
        insert(value);
    }

    // Call the function to print the third last element
    print_Third_Last_Element();

    return 0;
}