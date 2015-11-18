// to find the inorder successor of every node in a binary tree
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
	node* next;
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
void populate(node* root)
{
	node* next=NULL;
	if(root)
	{
		populate(root->right);
		root->next=next;
		next=root;
		populate(root->left);
	}
}
node* left(node* root)
{
	if(root->left==NULL)
		return root;
	left(root->left);
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	populate(r);	
	node* r1=left(r);
	cout<<r1->data<<endl;
	while(r1!=NULL)
	{
		cout<<r1->data<<" ";
		r1=r1->next;
	}	
	cout<<endl;
	return 0;
}
