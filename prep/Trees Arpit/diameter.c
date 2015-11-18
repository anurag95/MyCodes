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
int height(node* root) // also finds the maximum depth of the tree
{
	if(root==NULL)
		return 0;
	return (1+max(height(root->left),height(root->right)));
}
int diameter(node* root)
{
	if(root==NULL)
		return 0;
	int h1=height(root->left);
	int h2=height(root->right);
	int l=diameter(root->left);
	int r=diameter(root->right);
	return max((h1+h2+1),max(l,r));
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,5);
	insert(&r,2);
	insert(&r,15);
	insert(&r,30);
	insert(&r,1);
	cout<<search1(r,31)<<endl;	
	//cout<<diameter(r)<<endl;	
	//cout<<leafcount(r)<<endl;	
	//cout<<levelnode(r,5)<<endl;	
	//iterpostorder(r);	
	//inorder(r);		
	//cout<<endl<<ifindmin(r)<<endl;	
	//cout<<endl<<ifindmax(r)<<endl;	
	//cout<<isBST(r)<<endl;	
	return 0;
}
