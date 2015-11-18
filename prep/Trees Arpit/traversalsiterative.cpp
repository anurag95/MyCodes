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
void iterativepreorder(node* root)
{
	stack< node* >s;
	s.push(root);
	while(!s.empty())
	{
		node* curr=s.top();
		cout<<curr->data<<" ";
		s.pop();
		if(curr->right)
			s.push(curr->right);
		if(curr->left)
			s.push(curr->left);
	}
	return;
}
void iterativeinorder(node* root)
{
	node* curr=root;
	stack< node* >s;
	bool done=0;
	while(!done)
	{
		if(curr)
		{
			s.push(curr);
			curr=curr->left;
		}
		else
		{
			if(s.empty())
				done=1;
			else
			{
				curr=s.top();
				cout<<curr->data<<" ";
				s.pop();
				curr=curr->right;
			}
		}
	}
	return;
}
void iterativepostorder(node* root)
{
	stack< node* >s1;
	stack< node* >s2;
	s1.push(root);
	while(!s1.empty())
	{
		node* curr=s1.top();
		s1.pop();
		s2.push(curr);
		if(curr->left)
			s1.push(curr->left);
		if(curr->right)
			s1.push(curr->right);
	}
	while(!s2.empty())
	{
		cout<<s2.top()->data<<" ";
		s2.pop();
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
	iterativepreorder(r);
	cout<<endl;
	iterativepostorder(r);
	cout<<endl;
	iterativeinorder(r);
	cout<<endl;
	return 0;
}
