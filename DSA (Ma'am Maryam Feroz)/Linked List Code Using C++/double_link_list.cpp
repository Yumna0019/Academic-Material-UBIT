#include <iostream>

struct Node
{
    int ID;
    int marks;
    Node *next = NULL;
    Node *prev = NULL;
};

struct Node *start = NULL;

void insertNode()
{
    Node *temp = new Node();
    std::cout << "enter id: ";
    std::cin >> temp->ID;
    std::cout << "enter marks: ";
    std::cin >> temp->marks;
    temp->next = NULL;
    temp->prev = NULL;
    struct Node *curr = start;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}

void print()
{
    struct Node *curr = start;
    std::cout << std::endl;
    while (curr != NULL)
    {
        std::cout << "ID:" << curr->ID << "\t";
        std::cout << "Marks: " << curr->marks;
        std::cout << std::endl;
        curr = curr->next; // moving the current pointer to next node
    }
}

int DeleteSpecific(int toSearch)
{
    struct Node *curr = start;
    while (curr != NULL)
    {
        if (curr->ID == toSearch)
        {
            if (curr->prev == NULL)
            {
                // If the current node is the first node, update the start pointer to the next node
                start = curr->next;
            }
            else
            {
                // If the current node is not the first node, update the previous node's next pointer
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL)
            {
                // Update the next node's previous pointer if it exists
                curr->next->prev = curr->prev;
            }
            struct Node *temp = curr->next; // Store the next node before deleting the current node
            delete curr;                    // delete current node
            curr = temp;                    // Move to the next node
            return 1;                       // Indicate successful deletion
        }
        // Move the current pointer to the next node
        curr = curr->next;
    }
    return 0; // Indicate that the specified ID was not found
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        insertNode();
    }
    std::cout << "Before Deleting Specific Search ID";
    print();

    int toSearch;
    std::cout << "Enter deleteing ID: " << std::endl;
    std::cin >> toSearch;

    DeleteSpecific(toSearch);
    std::cout << "After Deleting Specific Search ID" << std::endl;
    print();

    return 0;
}
