// to find height of the given binary tree recursively
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
int levell(node* root,int level)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return level;
	int l1=levell(root->left,level+1);
	int l2=levell(root->right,level+1);
	return max(l1,l2);
}	
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	cout<<levell(r,1)<<endl;	
	return 0;
}
