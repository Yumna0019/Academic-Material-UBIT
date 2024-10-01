#include <iostream>
#include<climits>
using namespace std;

struct ddl
{
    int data;
    ddl *next;
    ddl *prev;
};

struct ddl *start = NULL;

void insert(int value)
{
    struct ddl *temp = new ddl();
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct ddl *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}

void reverse()
{
    struct ddl *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    cout << "Reversed Double List: ";
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

int findMin()
{
    if (start == NULL) {
        return INT_MAX; 
    }

    int min = start->data;
    struct ddl *curr = start;
    while (curr != NULL)
    {
        if (curr->data < min)
        {
            min = curr->data;
        }
        curr = curr->next;
    }
    return min;
}

int findMax()
{
    if (start == NULL) {
        return INT_MIN; 
    }

    int max = start->data;
    struct ddl *curr = start;
    while (curr != NULL)
    {
        if (curr->data > max)
        {
            max = curr->data;
        }
        curr = curr->next;
    }
    return max;
}

void print()
{
    struct ddl *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    cout << "Double list: ";
    insert(12);
    insert(44);
    insert(34);
    print();

    cout << "Minimum value: " << findMin() << endl;
    cout << "Maximum value: " << findMax() << endl;

    cout << "Reversed: ";
    reverse();

    return 0;
}