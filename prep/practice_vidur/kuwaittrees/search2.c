// search for a particular key in a binary search tree
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
void insert(node** root,int key)
{
	if((*root)==NULL)
	{
		(*root)=(struct node*)malloc(sizeof(struct node));
		(*root)->data=key;
		(*root)->left=NULL;
		(*root)->right=NULL;
	}
	else if((*root)->data>key)
		insert((&(*root)->left),key);
	else
		insert((&(*root)->right),key);
	return;
}
bool search(node* root,int key)
{
	if(root==NULL)
		return 0;
	else if(root->data==key)
		return 1;
	else if(root->left!=NULL && root->right!=NULL)
	{
		if(root->data>key)
			return search(root->left,key);
		else
			return search(root->right,key);
	}
	else if(root->left!=NULL)
	{
		if(root->data>key)
			return search(root->left,key);
		else
			return 0;
	}
	else if(root->right!=NULL)
	{
		if(root->data<key)
			return search(root->right,key);
		else
			return 0;
	}
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	cout<<search(r,30)<<endl;
	return 0;
}
