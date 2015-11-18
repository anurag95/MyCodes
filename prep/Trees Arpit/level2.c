// to print the level order traversal of the given binary tree in spiral form
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
void level(node* root)
{
	stack< node* >s;
	queue< pair<node*,int> >q;
	q.push(make_pair(root,1));
	while(!q.empty())
	{
		node* curr=q.front().first;
		int h=q.front().second;
		q.pop();
		if(h%2==0)
		{
			while(!s.empty())
			{
				cout<<s.top()->data<<" ";
				s.pop();
			}			
			cout<<curr->data<<" ";
		}		
		else
			s.push(curr);
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
	}
	while(!s.empty())
	{
		cout<<s.top()->data<<" ";
		s.pop();
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
	level(r);	
	return 0;
}
