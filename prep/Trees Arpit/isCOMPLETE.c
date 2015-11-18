// to determine whether the gieven binary tree is complete or not
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
int check(node* root)
{
	int g=0;
	queue< pair< node* ,int > >q;
	q.push(make_pair(root,1));
	while(!q.empty())
	{
		int h1=0;
		node* curr=q.front().first;
		int h=q.front().second;
		q.pop();		
		if(mymap[h]==1)
			g=1;
		if(curr->left)
		{
			h1=1;
			q.push(make_pair(curr->left,h+1));
		}
		if(curr->right)
		{
			q.push(make_pair(curr->right,h+1));
			if(h1==0)
				mymap[h+1]=1;
		}
		if(h1==0)
			mymap[h+1]=1;
	}
	return g;
}
int main()
{
	node* r1=NULL;
	insert(&r1,10);
	insert(&r1,20);
	//insert(&r1,19);
	insert(&r1,21);
	//insert(&r1,18);
	insert(&r1,8);
	insert(&r1,4);
	insert(&r1,9);
	int yu=check(r1);
	if(yu==0)
		cout<<"Complete"<<endl;
	else
		cout<<"Not Complete"<<endl;	
	return 0;
}
