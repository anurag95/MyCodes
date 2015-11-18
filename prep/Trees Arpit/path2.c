// to check whether a number equals to the possible sum of the root to leaf paths
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
int path(node* root,int sum,int key)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
	{
		sum=sum+root->data;
		if(sum==key)
		{
			sum=sum-root->data;
			return 1;
		}
		else
		{
			sum=sum-root->data;
			return 0;
		}
	}
	sum=sum+root->data;
	int l1=0,l2=0;
	if(root->left)
		l1=path(root->left,sum,key);		
	if(root->right)
		l2=path(root->right,sum,key);
	sum=sum-root->data;
	return l1 | l2;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	cout<<path(r,0,10)<<endl;	
	return 0;
}
