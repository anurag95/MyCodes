// to find the ancestors of a given node of a binary tree without recursion
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
void path(node* root,int key)
{
	int parent[1000]={0};
	node* curr=root;
	parent[curr->data]=0;
	queue< node* >q;
	q.push(curr);	
	while(!q.empty())
	{
		curr=q.front();
		q.pop();		
		if(curr->left)
		{
			parent[curr->left->data]=curr->data;
			q.push(curr->left);
		}
		if(curr->right)
		{
			parent[curr->right->data]=curr->data;
			q.push(curr->right);
		}
	}
	while(parent[key]!=0)
	{
		cout<<parent[key]<<" ";
		key=parent[key];
	}
	return;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	path(r,9);
	cout<<endl;	
	return 0;
}
