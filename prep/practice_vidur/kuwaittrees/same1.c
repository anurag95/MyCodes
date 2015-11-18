// to check whether the two given binary trees are same or not
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
int check(node* root1,node* root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	else if(root1!=NULL && root2!=NULL)
		return ((root1->data==root2->data) && check(root1->left,root2->left) && check(root1->right,root2->right));
	else
		return 0;
}
int main()
{
	node* r1=NULL;
	insert(&r1,10);
	insert(&r1,20);
	insert(&r1,8);
	insert(&r1,4);
	insert(&r1,9);
	node* r2=NULL;
	insert(&r2,10);
	insert(&r2,20);
	insert(&r2,8);
	insert(&r2,4);
	//insert(&r2,9);
	cout<<check(r1,r2);
	cout<<endl;	
	return 0;
}
