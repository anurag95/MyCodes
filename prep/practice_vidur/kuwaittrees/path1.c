// to find the ancestors of a given node of a binary tree
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
	if(root->data==key)
	{
		for(int yu=0;yu<v.size();yu++)
			cout<<v[yu]<<" ";
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
	path(r,20);
	cout<<endl;	
	return 0;
}
