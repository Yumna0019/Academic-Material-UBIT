#include <iostream>
#include <cstdlib>
#include <limits> // Include the <limits> header for input buffer clearing

struct Node
{
    int add;    // Integer value stored in the node
    Node *next; // Pointer to the next node
};
struct Node *start = NULL; // Initialize the 'start' pointer to NULL

// Function to calculate the median of the linked list
double calculateMedian()
{
    if (start == NULL)
    {
        return 0.0; // Return 0 if the list is empty
    }

    struct Node *slow = start; // Initialize a slow pointer to the start
    struct Node *fast = start; // Initialize a fast pointer to the start
    struct Node *prev = start; // Initialize a previous pointer to the start

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;             // Update 'prev' to the current 'slow'
        slow = slow->next;       // Move 'slow' one step
        fast = fast->next->next; // Move 'fast' two steps
    }

    if (fast == NULL)
    {
        // Even number of elements, so the median is the average of two middle elements
        return (prev->add + slow->add) / 2.0;
    }
    else
    {
        // Odd number of elements, so the median is the middle element
        return slow->add;
    }
}

// Function to insert a new node into the linked list
void add()
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    while (true)
    {
        std::cout << "Enter an integer (1-100) or enter -1 to exit: ";
        if (!(std::cin >> temp->add))
        {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();                                                   // Clear the input error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        }
        if (temp->add == -1)
        {
            free(temp); // Free memory for the unused node
            exit(0);    // Exit the loop if the user enters -1
        }
        else if (temp->add < 1 || temp->add > 100)
        {
            std::cout << "Invalid input. Please enter an integer between 1 and 100." << std::endl;
        }
        else
        {
            break; // Exit the input loop
        }
        std::cout << "Enter an integer (1-100) or enter -1 to exit: ";
    }

    temp->next = NULL; // Set the 'next' pointer of the new node to NULL

    // Check if the linked list is empty or the new node should be inserted at the beginning
    if (start == NULL || temp->add < start->add)
    {
        temp->next = start; // Set the 'next' pointer of the new node to the current start node
        start = temp;       // Update the 'start' pointer to the new node
    }
    else
    {
        struct Node *curr = start;                                 // Create a pointer 'curr' to traverse the list
        while (curr->next != NULL && curr->next->add <= temp->add) // Traverse to find the insertion point
        {
            curr = curr->next; // Move 'curr' to the next node
        }
        temp->next = curr->next; // Set the 'next' pointer of the new node to the next node of 'curr'
        curr->next = temp;       // Update 'curr' to point to the new node
    }
}

int main()
{
    while (true)
    {
        add(); // Insert the valid input into the linked list
        double median = calculateMedian();
        std::cout << "Median: " << median << std::endl;

        if (start->add == -1)
        {
            exit(0); // Exit the loop
        }
    }

    return 0;
}
