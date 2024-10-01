/* LIFO : Last In First Out. */
#include<iostream>
#include<stdlib.h>

struct Node 
{
    int data;
    Node* next;
    Node* prev;
};
struct Node *top=NULL;

void push()
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));

    std::cout<<"Enter Number: ";
    std::cin>>temp->data;
    temp->next=NULL;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        top->prev=temp;
        temp->next=top;
        top=temp;
    }
}

void popp()
{
    struct Node* curr = top;
    top = top->next;
    free(curr);
}

void print()
{
    if(top==NULL)
    {
        std::cout<<"List is empty"<<std::endl;
    }
    struct Node* curr=top;
    while (curr!=NULL)
    {
        std::cout<< curr->data <<" -> ";
        curr=curr->next;
    }
    std::cout<< "null" << std::endl;
} 

int main()
{
    push();
    push();
    push();
    print();
    popp();
    print();

    return 0;
}