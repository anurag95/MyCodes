// find the lca of the two nodes in a BST
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
node* find(node* root,int n1,int n2)
{
	while(root!=NULL)
	{
		if(root->data > n1 && root->data > n2)
			root=root->left;
		else if(root->data < n1 && root->data < n2)
			root=root->right;
		else		
			break;
	}
	return root;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	node* yo=find(r,4,9);
	cout<<yo->data<<endl;	
	return 0;
}
