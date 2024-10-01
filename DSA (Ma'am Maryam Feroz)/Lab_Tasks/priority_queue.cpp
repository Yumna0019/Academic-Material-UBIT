// you need to take input the name of the task and its priority from user
// to store in the queue. whenever a task is removed from the queue the next
// highest priority task will be placed in front . if two tasks with same priority
// enter then the first entered process is removed first.
// implement this as a priority queue using c++ don't use builtin priority queue
#include <iostream>
using namespace std;

struct priority
{
    int pty;
    string task;
    priority *next;
};
priority *head = NULL;

void insert(int pr, string tk)
{
    struct priority *temp = new struct priority;
    temp->pty = pr;
    temp->task = tk;

    if (head == NULL || pr > head->pty)
    {
        temp->next = head;
        head = temp;
    }
    else if (pr == head->pty)
    {
        struct priority *curr = head->next;
        head->next = temp;
        temp->next = curr;
    }
    else
    {
        struct priority *curr = head;
        temp->next = NULL;
        while (curr->next != nullptr && pr < curr->next->pty)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void deleteTask()
{
    struct priority *curr = head;
    head = head->next;
    free(curr);
}
void display()
{
    struct priority *curr = head;
    while (curr != nullptr)
    {
        cout << curr->pty << " " << curr->task << endl;
        curr = curr->next;
    }
}

int main()
{
    insert(10, "Task1");
    insert(100, "Task2");
    insert(120, "Task3");
    insert(1, "Task4");
    insert(0, "Task5");
    insert(120, "Task6");
    display();
    cout << endl;
    cout << "after deletion:\n " << endl;
    deleteTask();
    display();

    return 0;
}