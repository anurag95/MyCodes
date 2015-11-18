// to find the largest independent set of the binary tree
// collection of nodes such that no two nodes have a edge in common
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int liss;
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
int ans(node* root)
{
	if(root==NULL)
		return 0;
	int size1=0,size2=1;
	size1=ans(root->left)+ans(root->right);
	if(root->left)
		size2+=ans(root->left->left)+ans(root->left->right);
	if(root->right)
		size2+=ans(root->right->left)+ans(root->right->right);
	return max(size1,size2);
}
int memoans(node *root)
{
	if(root == NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return (root->liss = 1);
	if(root->liss)
		return root->liss;

	int excl = memoans(root->right)+memoans(root->left);
	int incl = 1;
	if(root->left)
		incl += memoans(root->left->left)+memoans(root->left->right);
	if(root->right)
		incl += memoans(root->right->left)+memoans(root->right->right);
	root->liss = max(incl, excl);
	return root->liss;
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
	cout<<ans(r)<<endl;	
	return 0;
}
