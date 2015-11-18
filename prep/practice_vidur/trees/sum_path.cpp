#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

bool has_sum_path(node* root, int sum)
{ 
	if(root == NULL)
		return (sum == 0);

	int rem = sum - root->data;
	if(rem == 0 && root->left == NULL && root->right == NULL)
		return 1;
	return  has_sum_path(root->left, rem) || has_sum_path(root->right, rem);
}

node* new_node(int x)
{
	node* temp = new node;
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
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
	node* root = new_node(10);
	root->left = new_node(8);
	root->right = new_node(2);
	root->left->left = new_node(3);
	root->left->right = new_node(5);
	root->right->left = new_node(2);
	if(has_sum_path(root, 21))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	remove(root);
	return 0;
}