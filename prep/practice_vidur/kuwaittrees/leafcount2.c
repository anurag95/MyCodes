// number of leaves in a binary tree iteratively
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
int leafcount(node* root)
{
	stack< node* >s;
	int h=0,k=0;
	s.push(root);
	while(!s.empty())
	{
		h=0;
		node* curr=s.top();
		s.pop();		
		if(curr->left)
		{	
			s.push(curr->left);
			h=1;
		}		
		if(curr->right)
		{
			s.push(curr->right);
			h=1;
		}
		if(h==0)
			k++;
	}
	return k;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	//insert(&r,9);
	cout<<leafcount(r)<<endl;
	return 0;
}
