// find the lca of the two nodes of the binary tree
#include <bits/stdc++.h>
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
node* find(node* root,int n1,int n2)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;

	node* left=find(root->left,n1,n2);
	node* right=find(root->right,n1,n2);
	
	if(left!=NULL && right!=NULL)
		return root;
	if(left!=NULL)
		return left;
	else
		return right;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	node* yo=find(r,4,8);
	cout<<yo->data<<endl;	
	return 0;
}
