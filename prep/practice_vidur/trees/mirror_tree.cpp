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

void mirror_tree(node* root)
{
	if(root == NULL)
		return;
	mirror_tree(root->left);
	mirror_tree(root->right);
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
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
	print(root);
	cout<<endl;
	mirror_tree(root);
	print(root);
	cout<<endl;
	remove(root);
	return 0;
}