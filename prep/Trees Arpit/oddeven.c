// to find the difference between the sum of nodes at odd level and nodes at even level
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
pair<int,int> level(node* root)
{
	int sum1=0,sum2=0;
	queue< pair<node*,int> >q;
	node* curr=root;
	q.push(make_pair(curr,1));	
	while(!q.empty())
	{
		curr=q.front().first;
		int h=q.front().second;
		q.pop();		
		if(h%2!=0)
			sum1+=curr->data;
		else
			sum2+=curr->data;
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
	}
	return make_pair(sum1,sum2);
}	
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	pair<int,int>p1=level(r);
	cout<<abs(p1.first-p1.second)<<endl;	
	return 0;
}
