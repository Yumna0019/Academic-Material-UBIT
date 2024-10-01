#include <iostream> // Input and output stream library
#include <cstdlib>  // C Standard Library for memory allocation
#include <limits>   // Include the <limits> header for input buffer clearing
#include <fstream>  // File stream library
#include <string>   // String library

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
void add(int number)
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    // Set the 'add' value of the new node
    temp->add = number;
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
    double median = calculateMedian();
    std::cout << "Median: " << median << std::endl;
}



// Function to read commands from a file and perform corresponding actions
void Read_File()
{
    std::string filepath;
    std::cout << "Enter the file path: " << std::endl;
    std::cin >> filepath;
    std::ifstream inputFile(filepath);

    if (!inputFile)
    {
        std::cout << "Error Opening the file." << std::endl;
        return;
    }

    int number;

    while (inputFile >> number)
    {
        add(number);
    }

    inputFile.close();

    return;
}



int main()
{
    // Call the function to read commands from a file and perform actions
    Read_File();

    return 0;
}
