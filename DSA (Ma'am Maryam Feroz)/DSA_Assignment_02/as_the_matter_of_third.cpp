#include <iostream> // Input and output stream library
#include <cstdlib>  // C Standard Library for memory allocation
#include <limits>   // Include the <limits> header for input buffer clearing
#include <fstream>  // File stream library
#include <string>   // String library

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

    int value;

    while (inputFile >> value)
    {
        insert(value);
    }
    print_Third_Last_Element();
    

    inputFile.close();
}



int main()
{
    // Call the function to read commands from a file and perform actions
    Read_File();

    return 0;
}
