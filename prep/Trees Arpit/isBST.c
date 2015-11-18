// check whether the given binary tree is a binary search tree
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
bool isBST(node* root)
{
	if(root->left==NULL && root->right==NULL)
		return 1;
	else if(root->left!=NULL && root->right!=NULL)
	{
		if(root->data>(root->left)->data && root->data<(root->right)->data)
			return (isBST(root->left) & isBST(root->right));	
		else
			return 0;
	}
	else if(root->left!=NULL)
	{
		if(root->data>((root->left)->data))
			return isBST(root->left);
		else
			return 0;
	}
	else if(root->right!=NULL)
	{
		if(root->data<((root->right)->data))
			return isBST(root->right);
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
	cout<<isBST(r)<<endl;
	return 0;
}
