#include<iostream>  
#include<stdlib.h>  

// Define a structure for a linked list node
struct Node {
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
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    // Taking input of id and marks from the user 
    std::cout << "Enter the id: ";
    std::cin >> temp->id;
    std::cout << "Enter the marks: ";
    std::cin >> temp->marks;
    
    temp->next = NULL; // Set the 'next' pointer of the new node to NULL

    // Check if the linked list is empty
    if(start == NULL)
    {
        start = temp; // If empty, set the 'start' pointer to the new node
        return;
    }
    else
    {
        struct Node *curr = start; // Create a pointer 'curr' to traverse the list
        while(curr->next != NULL) // Traverse to the last node
        {
            curr = curr->next; // Move 'curr' to the next node
        }
        curr->next = temp; // Set the 'next' pointer of the last node to the new node
        // temp = temp->next;  // This line is not necessary and can be removed
    }
}

// Function to print the elements of the linked list
void print()
{
    if(start == NULL)
    {
        std::cout << "List is empty." << std::endl;
    }
    struct Node *curr = start; // Create a pointer 'curr' to traverse the list
    
    // Print each node's id
    while(curr != NULL) // Traverse until the end of the list
    {
        std::cout << curr->id << " "; // Print the current node's id
        curr = curr->next; // Move 'curr' to the next node
    }   
    std::cout << std::endl;
}

// Function to delete a specific id in the linked list
bool deletion()
{
    int todelete; // Variable to store the id to be deleted
    std::cout << "Enter the id you want to delete: " << std::endl;
    std::cin >> todelete; // Read the id to be deleted
    struct Node *curr = start; // Create a pointer 'curr' to traverse the list
    
    // Check if the linked list is empty
    if(start == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return true;
    }
    
    // Check if the first node should be deleted
    if(start->id == todelete)
    {
        start = start->next; // Update the 'start' pointer to the next node
        free(curr); // Deallocate memory for the deleted node
        return true; // Return true to indicate success
    }
    else
    {
        struct Node* prev = start; // Create a pointer 'prev' to keep track of the previous node
        struct Node* curr = start->next; // Start 'curr' from the second node
                
        // Traverse the linked list to find the node to delete
        while(curr != NULL)
        {
            if(curr->id == todelete) // Check if the current node's id matches the id to delete
            {
                prev->next = curr->next; // Adjust the 'next' pointer of the previous node
                free(curr); // Deallocate memory for the deleted node
                break; // Exit the loop once the node is deleted
                return true;            
            }
            else
            {                            
                prev = curr; // Move 'prev' to the current node
                curr = curr->next; // Move 'curr' to the next node
            }
        }
    }
    //return false;
}

void Deleteprint()
{
    if(deletion())
    {
        std::cout<<"Deletion is done"<<std::endl;
    }
    else
    {
        std::cout<<"Given number is not in the list."<<std::endl;   
    }
} 
void deletAll()
{
    struct Node* curr = start; // Create a pointer 'curr' to traverse the list
    while(curr != NULL) // Traverse until the end of the list
    {
        curr = curr->next; // Move 'curr' to the next node
        free(curr); // Deallocate memory for the current node
    }
    start = curr; // You should set the 'start' pointer to NULL to indicate an empty list
}

int main()
{
    insert(); // Insert the first element
    insert(); // Insert the second element
    insert(); // Insert the third element
    
    std::cout << std::endl;
    std::cout << "List before deleting an element: " << std::endl;
    print(); // Print the list of id elements
    std::cout << std::endl;
    
    Deleteprint(); // Delete a specific id
    
    
    std::cout << "List after deletion: " << std::endl;
    print(); // Print the list of id elements after deletion
    
    deletAll(); // Delete All elements (also fix the typo in the function name)
    std::cout<<"After deleting all list."<<std::endl;
    print();  // Print the list (which should be empty at this point)
    
    return 0; // Exit the program 
}
