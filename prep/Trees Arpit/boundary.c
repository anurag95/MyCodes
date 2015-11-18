// to perform the boundary order traversal of the given binary tree
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
void left(node* root)
{
	if(root==NULL)
		return;
	if(mymap[root->data]==0)	
		cout<<root->data<<" ";
	mymap[root->data]=1;
	left(root->left);
	return;
}
void right(node* root)
{
	if(root==NULL)
		return;
	right(root->right);
	if(mymap[root->data]==0)
		cout<<root->data<<" ";
	mymap[root->data]=1;
	return;
}
void printleaf(node* root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		if(mymap[root->data]==0)
			cout<<root->data<<" ";
		mymap[root->data]=1;
	}
	printleaf(root->left);
	printleaf(root->right);
	return;
}
int main()
{
	node* r1=NULL;
	insert(&r1,10);
	insert(&r1,20);
	insert(&r1,19);
	insert(&r1,21);
	insert(&r1,18);
	insert(&r1,8);
	insert(&r1,4);
	insert(&r1,9);
	left(r1);
	printleaf(r1);
	right(r1);
	cout<<endl;	
	return 0;
}
