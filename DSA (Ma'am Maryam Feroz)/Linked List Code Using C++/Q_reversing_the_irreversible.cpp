#include <iostream>
#include <cstdlib>

struct Node
{
    int trans_Id;     // Transaction ID
    int trans_Amount; // Transaction Amount
    Node *next;
};

struct Node *start = NULL; // Initialize the linked list as empty

void transaction()
{
    int num_of_IDs, num_of_fraud_IDs;

    // Prompt user for the number of transactions and fraudulent transactions
    std::cout << "Enter Number Of Transactions and Fraudulent Transactions (e.g., 5 2): ";
    std::cin >> num_of_IDs >> num_of_fraud_IDs;

    for (int i = 0; i < num_of_IDs; ++i)
    {
        // Allocate memory for a new transaction node
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        // Prompt user to enter Transaction ID and Amount
        std::cout << "Enter Transaction ID and Amount (e.g., ID Amount): ";
        std::cin >> temp->trans_Id >> temp->trans_Amount;

        temp->next = NULL; // Set the next pointer to NULL

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

    std::cout << std::endl; // Print a blank line

    for (int i = 0; i < num_of_fraud_IDs; ++i)
    {
        int fraud_id;
        std::cout << "Enter Fraudulent ID: ";
        std::cin >> fraud_id;

        // Find the transaction with the fraudulent ID and set its amount to 0
        Node *current = start;
        while (current != NULL)
        {
            if (current->trans_Id == fraud_id)
            {
                current->trans_Amount = 0;
                break;
            }
            current = current->next;
        }
    }

    std::cout << std::endl;
    std::cout << "Transaction IDs and Amounts (fraudulent IDs will have an amount of 0):" << std::endl;

    // Display the transactions with updated amounts
    Node *current = start;
    while (current != NULL)
    {
        std::cout << "Transaction ID: " << current->trans_Id << " , Amount: " << current->trans_Amount << std::endl;
        current = current->next;
    }
}

int main()
{
    transaction();
    return 0;
}
