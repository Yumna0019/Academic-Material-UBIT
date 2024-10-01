#include <iostream> // Input and output stream library
#include <fstream>  // File stream library
#include <string>   // String library for string manipulation
#include <cstdlib>  // C Standard Library for memory allocation

// Define a structure for a linked list node representing a transaction
struct Node
{
    int trans_Id;     // Transaction ID
    int trans_Amount; // Transaction Amount
    Node *next;       // Pointer to the next transaction node
};

struct Node *start = NULL; // Initialize the linked list as empty



// Function to insert a new transaction into the linked list
void Insert_Transaction(int trans_id, int trans_amount)
{
    // Allocate memory for a new transaction node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->trans_Id = trans_id;
    temp->trans_Amount = trans_amount;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp; // If the list is empty, set 'start' to the new node
    }
    else
    {
        struct Node *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next; // Traverse to the end of the list
        }
        curr->next = temp; // Add the new node to the end of the list
    }
}



// Function to delete a transaction with a fraudulent ID
void Delete_Fraud_Transaction(int fraud_id)
{
    // Find the transaction with the fraudulent ID and set its amount to 0
    Node *current = start;
    while (current != NULL)
    {
        if (current->trans_Id == fraud_id)
        {
            current->trans_Amount = 0; // Update the amount to 0
            break;
        }
        current = current->next;
    }
}



// Function to print valid transactions (amount > 0)
void Print_Transactions()
{
    Node *current = start;
    while (current != NULL)
    {
        if (current->trans_Amount > 0)
        {
            std::cout << current->trans_Id << "," << current->trans_Amount << std::endl;
        }
        current = current->next;
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

    int num_of_transactions, num_of_fraud_IDs;
    inputFile >> num_of_transactions >> num_of_fraud_IDs;
    inputFile.ignore(); // Consume the newline character

    // Read and insert transactions
    for (int i = 0; i < num_of_transactions; ++i)
    {
        int trans_id, trans_amount;
        char comma;
        inputFile >> trans_id >> comma >> trans_amount;
        Insert_Transaction(trans_id, trans_amount);
    }

    // Read and delete fraudulent transactions
    for (int i = 0; i < num_of_fraud_IDs; ++i)
    {
        int fraud_id;
        inputFile >> fraud_id;
        Delete_Fraud_Transaction(fraud_id);
    }

    // Print valid transactions
    Print_Transactions();

    inputFile.close();
}



int main()
{
    // Call the function to read commands from a file and perform actions
    Read_File();

    return 0;
}
