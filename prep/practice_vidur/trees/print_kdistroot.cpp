#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* new_node(int x)
{
	node* temp = new node;
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void print_kdist(node* root, int k)
{
	if(root == NULL)
		return;
	if(k == 0)
	{
		cout<<root->data<<" ";
		return;
	}
	print_kdist(root->left, k - 1);
	print_kdist(root->right, k - 1);
}

void print(node* root)
{
	if(root == NULL)
		return;
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}

void remove(node* root)
{
	if(root == NULL)
		return;
	remove(root->left);
	remove(root->right);
	delete root;
}

int main()
{
	node* root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(8);
	int k = 2;
	print(root);
	cout<<endl;
	print_kdist(root, k);
	cout<<endl;
	remove(root);
	return 0;
}