/* FIFO: First In Firt Out. */
#include <iostream>

struct Node
{
    int data;
    Node *next;
};
struct Node *head = NULL;

void enqueue()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    std::cout << "Enter Number: ";
    std::cin >> temp->data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void dequeue()
{
    struct Node *curr = head;
    head = head->next;
    free(curr);
}

void print()
{
    if (head == NULL)
    {
        std::cout << "List is empty." << std::endl;
    }
    struct Node *curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "null" << std::endl;
}

int main()
{
    enqueue();
    enqueue();
    enqueue();
    print();
    dequeue();
    print();
    return 0;
}