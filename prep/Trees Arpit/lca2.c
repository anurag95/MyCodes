// find the distance between the two nodes of the binary tree
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
int level(node* root,int n1,int n2,int n3)
{
	int max1,max2,max3;
	queue< pair<node* , int> >q;
	q.push(make_pair(root,1));
	while(!q.empty())
	{
		node* curr=q.front().first;
		int h=q.front().second;
		q.pop();
		if(curr->data==n1)
			max1=h;
		if(curr->data==n2)
			max2=h;
		if(curr->data==n3)
			max3=h;
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
	}
	return (max1+max2-(2*max3));
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	node* yo=find(r,4,20);
	int h2=yo->data;
	cout<<level(r,4,20,h2)<<endl;	
	return 0;
}
