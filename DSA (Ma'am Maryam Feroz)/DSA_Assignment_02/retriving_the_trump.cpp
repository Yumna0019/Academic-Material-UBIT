#include <iostream> // Input and output stream library
#include <fstream>  // File stream library
#include <string>   // String library
#include <cstdlib>  // C Standard Library for memory allocation

// Define a structure for a linked list node
struct Node
{
    int add;           // Integer data stored in the node
    struct Node *next; // Pointer to the next node in the linked list
};

// Initialize a pointer to the start of the linked list
struct Node *start = NULL; // Initialize the 'start' pointer to NULL



// Function to insert a new node into the linked list
void add(int number)
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    // Set the 'add' value of the new node
    temp->add = number;

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

    std::string line;
    int number;

    while (inputFile >> line)
    {
        if (line == "ADD")
        {
            if (inputFile >> number)
            {
                add(number);
            }
            else
            {
                std::cout << "Error: ADD command missing a number." << std::endl;
                return;
            }
        }
        else if (line == "DELETE")
        {
            deletion();
        }
        else if (line == "END")
        {
            GetTrump();
            return;
        }
    }

    inputFile.close();
}



int main()
{
    // Call the function to read commands from a file and perform actions
    Read_File();

    return 0;
}