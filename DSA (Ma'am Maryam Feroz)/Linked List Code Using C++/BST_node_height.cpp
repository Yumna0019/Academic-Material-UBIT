#include <iostream>

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

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

int height(BSTNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return std::max(left_height, right_height) + 1;
    }
}

void print_height(BSTNode *root)
{
    int tree_height = height(root);
    std::cout << "Total height of tree: " << tree_height << std::endl;
}

void print_InOrder(BSTNode *root)
{
    if (root != NULL)
    {
        print_InOrder(root->left);
        std::cout << "Node: " << root->data << "  ,  "
                  << "Height of node: " << height(root);
        std::cout << std::endl;
        print_InOrder(root->right);
    }
}

int main()
{
    BSTNode *root = NULL;
    root = insert(root, 57);
    insert(root, 32);
    insert(root, 68);
    insert(root, 21);
    insert(root, 59);
    insert(root, 135);
    insert(root, 18);
    insert(root, 120);
    insert(root, 11);
    insert(root, 100);
    insert(root, 75);

    print_InOrder(root);
    std::cout << std::endl;
    print_height(root);
}