// finding whether a particular key exists in a binary tree or not
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
bool exist(node* root,int key)
{
	if(root==NULL)
		return 0;
	if(root->data==key)
		return 1;
	int l1=exist(root->left,key);
	int l2=exist(root->right,key);	
	return l1|l2;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	cout<<exist(r,4)<<endl;
	return 0;
}
