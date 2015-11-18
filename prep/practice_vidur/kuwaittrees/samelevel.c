// to check whether the leaves of a binary tree are at the same level or not
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
	int a=0;
	queue< pair<node*,int> >q;
	node* curr=root;
	q.push(make_pair(curr,1));	
	while(!q.empty())
	{
		int yu=0;
		curr=q.front().first;
		int h=q.front().second;
		q.pop();		
		if(curr->left)
		{
			yu=1;			
			q.push(make_pair(curr->left,h+1));
		}
		if(curr->right)
		{
			yu=1;			
			q.push(make_pair(curr->right,h+1));
		}
		if(yu==0 && a==0)
			a=h;
		else if(yu==0 && a!=h)
			a=-1; 	
	}
	if(a!=-1)
		a=0;
	return a;
}	
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	insert(&r,50);	
	int p1=level(r);
	cout<<p1<<endl;	
	return 0;
}
