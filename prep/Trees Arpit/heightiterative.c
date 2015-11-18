// to find height of the given binary tree iteratively
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
int level(node* root)
{
	int val=0;
	queue< pair<node*,int> >q;
	node* curr=root;
	q.push(make_pair(curr,1));	
	while(!q.empty())
	{
		curr=q.front().first;
		int h=q.front().second;
		q.pop();		
		val=max(val,h);
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
	}
	return val;
}	
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	//insert(&r,4);
	//insert(&r,9);
	cout<<level(r)<<endl;	
	return 0;
}
