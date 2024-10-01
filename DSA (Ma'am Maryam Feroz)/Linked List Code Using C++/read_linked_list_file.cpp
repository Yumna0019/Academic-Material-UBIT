#include<iostream>

void read()
{
    int total ;
    std::string filePath;
    std::cout<< "Enter file path: ";
    getline(std::cin,filePath);
    std::ifstream inputFile(filePath);
    if(!inputFile)
    {
        std::cout << "Error.";
        return;
    }
    inputFile >> total;
    std::cout<< "The size of the array is: "<<total<<std::endl;
    for(int i= 0;i<total;i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        std::string element;
        temp->next=NULL;
        getline(inputFile, element , ' ');
        temp->add = stoi(element);
        if(start == NULL)
        {
            start=temp;
        }
        else
        {
            struct Node* curr=start;
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            curr->next=temp;
        }
    }
    inputFile.close();
}