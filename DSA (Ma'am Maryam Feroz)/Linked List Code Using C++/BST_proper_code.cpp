#include <iostream>

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

void print_InOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    print_InOrder(root->left);
    std::cout << root->data << " ";
    print_InOrder(root->right);
}

BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
    {
        BSTNode *temp = new BSTNode();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

BSTNode *search(BSTNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data == root->data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

BSTNode *update(BSTNode *root, int data, int update_value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data == root->data)
    {
        root->data = update_value;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

BSTNode *deletion(BSTNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = deletion(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletion(root->right, data);
    }
    else
    {
        // Node to be deleted is found.
        if (root->left == NULL && root->right == NULL)
        {
            // Leaf node
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            BSTNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            // Node has only left child
            BSTNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            // Node has both left and right child.
            // Find the smallest node in the right subtree.
            BSTNode *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            // Swap the data of the node to be deleted with the smallest node in the right subtree.
            int temp_data = temp->data;
            temp->data = root->data;
            root->data = temp_data;
            // Delete the smallest node in the rigght subtree.
            root->right = deletion(root->right, temp_data);
        }
    }
    return root;
}

int main()
{
    BSTNode *root = NULL;

    int choice;
    int data;
    int update_value;

    while (true)
    {
        std::cout << "Menu:\n";
        std::cout << "1. Insert.\n";
        std::cout << "2. Search.\n";
        std::cout << "3. Delete.\n";
        std::cout << "4. To Print InOrder.\n";
        std::cout << "5. Update.\n";
        std::cout << "6. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter the data to insert: ";
            std::cin >> data;
            root = insert(root, data);
            break;
        }
        case 2:
        {
            std::cout << "Enter the data to search: ";
            std::cin >> data;
            BSTNode *node = search(root, data);
            if (node != NULL)
            {
                std::cout << "Data found.\n";
            }
            else
            {
                std::cout << "Data not found.\n";
            }
            break;
        }
        case 3:
        {
            std::cout << "Enter the data to delete: ";
            std::cin >> data;
            root = deletion(root, data);
            if (data != NULL)
            {
                std::cout << "Data deleted.\n";
            }
            else
            {
                std::cout << "Data not found.\n";
            }
            break;
        }
        case 4:
        {
            print_InOrder(root);
            std::cout << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Enter the data to search: ";
            std::cin >> data;
            std::cout << "Enter the data to update: ";
            std::cin >> data;
            BSTNode *node = update(root, data, update_value);
            if (node != NULL)
            {
                std::cout << "Data update.\n";
            }
            else
            {
                std::cout << "Data not update.\n";
            }
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            std::cout << "Invalid choice.\n";
        }
        }
    }
    return 0;
}