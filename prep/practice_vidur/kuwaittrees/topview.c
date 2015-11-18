#include<bits/stdc++.h>
using namespace std;
map<int,int >mymap;
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
void top(node* root)
{
	int minn=INT_MAX,maxx=0;
	if(root==NULL)
		return;
	queue< pair< node* ,int> >q;
	q.push(make_pair(root,0));
	while(!q.empty())
	{
		node* curr=q.front().first;
		int h=q.front().second;
		q.pop();
		if(mymap[h]==0)
			mymap[h]=(curr->data);
		if(h<minn)
			minn=h;
		if(maxx<h)
			maxx=h;
		if(curr->left)
			q.push(make_pair(curr->left,h-1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
	}
	for(int yu=minn;yu<=maxx;yu++)
	{
		cout<<mymap[yu]<<" ";
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
	insert(&r,2);
	insert(&r,5);
	top(r);
	cout<<endl;
	return 0;
}
