// to check whether the given binary tree is full binary tree or not
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
bool full(node* root)
{
	if(root==NULL)
		return 1;
	else if(root->left!=NULL && root->right!=NULL)
		return (full(root->left) & full(root->right));
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return 0;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	insert(&r,25);
	cout<<full(r)<<endl;	
	return 0;
}
