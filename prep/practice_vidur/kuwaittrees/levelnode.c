// finding the level of a node of a binary tree iteratively
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
int levell(node* root,int level,int key)
{
	node* curr=root;
	queue< pair<node*,int> >q;
	q.push(make_pair(curr,1));
	while(!q.empty())
	{
		curr=q.front().first;
		int h=q.front().second;
		q.pop();
		if(curr->data==key)
			return h;		
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
	}
	return -1;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	cout<<levell(r,1,9)<<endl;
	return 0;
}
