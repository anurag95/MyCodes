// to print the left view of the binary tree
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
void leftview(node* root)
{
	map<int,int>mymap;	
	queue< pair<node*,int> >q;
	node* curr=root;
	q.push(make_pair(curr,1));	
	while(!q.empty())
	{
		curr=q.front().first;
		int h=q.front().second;
		q.pop();		
		if(mymap[h]==0)
		{
			cout<<curr->data<<" ";
			mymap[h]=1;
		}
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
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
	leftview(r);
	return 0;
}
