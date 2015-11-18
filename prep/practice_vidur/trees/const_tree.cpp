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

int search(int *inord, int start, int end, int key)
{
	for (int i = start; i <= end; ++i)
		if(key == inord[i])
			return i;
}

node* build_tree(int *inord, int *preord, int in_st, int in_end)
{
	static int pre_ind = 0;

	if(in_st > in_end)
		return NULL;

	node* temp = new_node(preord[pre_ind++]);

	if(in_st == in_end)
		return temp;

	int in_ind = search(inord, in_st, in_end, temp->data);

	temp->left = build_tree(inord, preord, in_st, in_ind-1);
	temp->right = build_tree(inord, preord, in_ind+1, in_end);

	return temp;
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
	int inord[] = {4,2,5,1,6,3};
	int preord[] = {1,2,4,5,3,6};
	int len = sizeof(inord)/sizeof(inord[0]);
	node* root = build_tree(inord, preord, 0, len - 1);
	print(root);
	cout<<endl;
	remove(root);
	return 0;
}