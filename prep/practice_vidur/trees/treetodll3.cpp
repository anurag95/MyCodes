#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *new_node(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void TreeToDLL(node *root, node **head)
{
	if(root == NULL)
		return;

	static node *prev = NULL;

	TreeToDLL(root->left, head);

	if(prev == NULL)
		*head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	TreeToDLL(root->right, head);
}

void print(node *head)
{
	node *curr = head;
	while(curr)
	{
		cout<<curr->data<<" ";
		curr = curr->right;
	}
	cout<<endl;
}

void inorder(node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	node *root = new_node(10);
	root->left = new_node(12);
	root->right = new_node(15);
	root->left->left = new_node(25);
	root->left->right = new_node(30);
	root->right->left = new_node(36);
	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;
	cout<<"Preorder: ";
	preorder(root);
	cout<<endl;

	node *head = NULL;
	TreeToDLL(root, &head);
	cout<<"List: ";
	print(head);
	return 0;
}