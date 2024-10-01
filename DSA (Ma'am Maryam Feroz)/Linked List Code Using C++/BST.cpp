#include <iostream>
using namespace std;

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode *insert(BSTNode *node, int value)
{
	if (node == NULL)
	{
		BSTNode *temp = new BSTNode();
		temp->data = value;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (value > node->data)
	{
		node->right = insert(node->right, value);
	}
	else
	{
		node->left = insert(node->left, value);
	}
	return node;
}

int InOrder(BSTNode *node)
{
	if (node != NULL)
	{
		InOrder(node->left);
		cout << node->data << endl;
		InOrder(node->right);
	}
}

int PreOrder(BSTNode *node)
{
	if (node != NULL)
	{
		cout << node->data << endl;
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

int PostOrder(BSTNode *node)
{
	if (node != NULL)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->data << endl;
	}
}

void search(BSTNode *node, int tosearch)
{
	if (node == NULL)
	{
		cout << "not found";
		return;
	}
	if (tosearch == node->data)
	{
		cout << "found";
		return;
	}
	if (tosearch > node->data)
	{
		search(node->right, tosearch);
	}
	else
	{
		search(node->left, tosearch);
	}
}

BSTNode *deletion(BSTNode *node, int todel)
{
	if (node == NULL)
	{
		cout << "not found";
		// return;
	}
	if (todel < node->data)
	{
		node->left = deletion(node->left, todel);
	}
	else if (todel > node->data)
	{
		node->right = deletion(node->right, todel);
	}
	else
	{ // having one child
		if (node->left == NULL)
		{
			BSTNode *temp;
			temp = node->right;
			delete (node);
			return temp;
		}
		if (node->right == NULL)
		{
			struct BSTNode *temp = node->left;
			delete (node);
			return temp;
		}
		else
		{
			// having two child
			struct BSTNode *temp = node->right;
			// find smallest
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			int sm = temp->data;
			node->data = sm;
			node->right = deletion(node->right, todel);
			// return temp;
		}
	}
}

void update(BSTNode *node, int value)
{
	if (node == NULL)
	{
		cout << "not found";
		return;
	}
	if (node->data == value)
	{
		int upd;
		cout << "Enter the update value";
		cin >> upd;
		node->data = upd;
		return;
	}
	if (value > node->data)
	{
		update(node->right, value);
	}
	else
	{
		update(node->left, value);
	}
}

int main()
{
	BSTNode *root = NULL;
	root = insert(root, 75);
	root = insert(root, 85);
	root = insert(root, 25);
	root = insert(root, 67);
	InOrder(root);
	int tosearch;
	cout << "Enter search value: ";
	cin >> tosearch;
	search(root, tosearch);
	int todel;
	cout << endl;
	cout << "Enter delete value: ";
	cin >> todel;
	deletion(root, todel);
	InOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	PreOrder(root);
	cout << endl;
	int upd;
	cout << "Enter number on which you want to update new value: ";
	cin >> upd;
	update(root, upd);
	InOrder(root);
}
