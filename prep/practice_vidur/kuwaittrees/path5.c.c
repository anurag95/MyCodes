// to print the nodes at a distance k from the leaf of the binary tree
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
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		if(key==0 && mymap[root->data]==0)
		{
			cout<<root->data<<" ";
			mymap[root->data]=1;
		}		
		else if(key<=v.size() && mymap[v[v.size()-key]]==0)
		{
			cout<<v[v.size()-key]<<" ";
			mymap[v[v.size()-key]]=1;
		}		
		return;
	}
	v.push_back(root->data);
	if(root->left)
		path(root->left,key);		
	if(root->right)
		path(root->right,key);
	v.erase(v.begin()+v.size()-1);
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
	path(r,3);	
	return 0;
}
