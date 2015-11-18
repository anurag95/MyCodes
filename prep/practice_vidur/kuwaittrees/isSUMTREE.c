// to check whether the given binary tree is a sum tree or not
// 1 : if a leaf node then just check whther sum of left and right node equals the value of current node
// 2 : if not a leaf node then check whether twice the sum of left and right node equals the value of node
#include<bits/stdc++.h>
using namespace std;
vector<int>v;
map<int,int>mymap;
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
int check(node* root)
{
	if(root==NULL)
		return 1;
	if(root->left==NULL && root->right==NULL)
		return 1;
	int l=0,r=0,k=0;
	if(root->left)	
	{
		if(root->left->left==NULL && root->left->right==NULL)
			l=root->left->data;
		else
			l=(root->left->data)*2;
	}
	if(root->right)
	{	
		if(root->right->left==NULL && root->right->right==NULL)
			r=root->right->data;
		else
			r=(root->right->data)*2;
	}	
	if((root->data)==(l+r))
		k=1;
	return (k && check(root->left) && check(root->right));
}
int main()
{
	node* r=NULL;
	insert(&r,20);
	insert(&r,5);
	insert(&r,18);
	insert(&r,4);
	insert(&r,9);
	cout<<check(r);
	cout<<endl;	
	return 0;
}
