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
int height(node* root) // also finds the maximum depth of the tree
{
	if(root==NULL)
		return 0;
	return (1+max(height(root->left),height(root->right)));
}
int search1(node* root,int key)
{
	if(root==NULL)
		return 0;
	if(root->data==key)
		return 1;
	int l1=0,l2=0;
	if(root->data>key)
		l1=search1(root->left,key);
	else
		l2=search1(root->right,key);
	return max(l1,l2);
}
int iterheight(node* root) // also finds the the maximum depth of the tree iteratively
{
	int val=0;	
	if(root==NULL)
		return -1;
	queue< pair<node* ,int> >q;
	q.push(make_pair(root,1));
	while(!q.empty())
	{
		node* curr=q.front().first;
		int h=q.front().second;		
		q.pop();		
		if(curr->left)		
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));
		val=max(val,h);
	}
	return val;
}
int diameter(node* root)
{
	if(root==NULL)
		return 0;
	int h1=height(root->left);
	int h2=height(root->right);
	int l=diameter(root->left);
	int r=diameter(root->right);
	return max((h1+h2+1),max(l,r));
}
int ifindmin(node* root)
{
	node* current=root;
	if(root!=NULL)
	{
		while(current->left!=NULL)
			current=current->left;
	}
	return current->data;
}
int ifindmax(node* root)
{
	node* current=root;
	if(root!=NULL)
	{
		while(current->right!=NULL)
			current=current->right;
	}
	return current->data;
}
int findmin(node* root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL)
			return findmin(root->left);
		else	
			return root->data;
	}
}
int findmax(node* root)
{
	if(root!=NULL)
	{
		if(root->right!=NULL)
			return findmax(root->right);
		else	
			return root->data;
	}
}		
void preorder(node* arr)
{
	if(arr==NULL)
		return;
	cout<<arr->data<<" ";
	preorder(arr->left);
	preorder(arr->right);
	return;
}
void postorder(node* arr)
{
	if(arr==NULL)
		return;
	postorder(arr->left);
	postorder(arr->right);
	cout<<arr->data<<" ";
	return;
}
void inorder(node* arr)
{
	if(arr==NULL)
		return;
	inorder(arr->left);
	cout<<arr->data<<" ";
	inorder(arr->right);
	return;
}
void levelorder(node* root)
{
	queue< node* >q;
	q.push(root);
	while(!q.empty())
	{
		node* curr=q.front();
		cout<<curr->data<<" ";
		q.pop();
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
	cout<<endl;
}
void iterpreorder(node* root)
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
	cout<<endl;
	return;
}
void iterinorder(node* root)
{
	stack< node* >s;
	node* curr=root;
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
				s.pop();
				cout<<curr->data<<" ";
				curr=curr->right;
			}
		}
	}
	cout<<endl;	
	return;
}
void iterpostorder(node* root)
{
	stack< node* >s1;
	stack< node* >s2;
	node* curr=root;
	s1.push(curr);
	while(!s1.empty())
	{
		curr=s1.top();
		s2.push(curr);
		s1.pop();
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
	cout<<endl;
	return;
}
int levelnode(node* root,int key)
{
	node* curr=root;
	queue< pair<node* , int> >q;
	q.push(make_pair(curr,1));
	while(!q.empty())
	{
		curr=(q.front()).first;
		int h=(q.front()).second;		
		if(curr->data==key)
			return h;		
		q.pop();
		if(curr->left)
			q.push(make_pair(curr->left,h+1));
		if(curr->right)
			q.push(make_pair(curr->right,h+1));				
	}
	return -1;
}			
int leafcount(node* root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return (leafcount(root->left) + leafcount(root->right));
}
bool search(node* root,int key)
{
	if(root==NULL)
		return 0;	
	else if(root->data==key)
		return 1;
	else if(root->data>key)
		return search(root->left,key);
	else
		return search(root->right,key);
}
bool sametree(node* root1 , node* root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	else if(root1!=NULL && root2!=NULL)
	{
		return ( root1->data==root2->data && sametree(root1->left,root2->left) && sametree(root1->right,root2->right));			
	}
	else
		return 0;
}
bool isBST(node* root)
{
	if(root->left==NULL && root->right==NULL)
		return 1;
	else if(root->left!=NULL && root->right!=NULL)
	{
		if(root->data>(root->left)->data && root->data<(root->right)->data)
			return (isBST(root->left) & isBST(root->right));	
		else
			return 0;
	}
	else if(root->left!=NULL)
	{
		if(root->data>((root->left)->data))
			return isBST(root->left);
		else
			return 0;
	}
	else if(root->right!=NULL)
	{
		if(root->data<((root->right)->data))
			return isBST(root->right);
		else
			return 0;
	}
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,5);
	insert(&r,2);
	insert(&r,15);
	insert(&r,30);
	insert(&r,1);
	cout<<search1(r,31)<<endl;	
	//cout<<diameter(r)<<endl;	
	//cout<<leafcount(r)<<endl;	
	//cout<<levelnode(r,5)<<endl;	
	//iterpostorder(r);	
	//inorder(r);		
	//cout<<endl<<ifindmin(r)<<endl;	
	//cout<<endl<<ifindmax(r)<<endl;	
	//cout<<isBST(r)<<endl;	
	return 0;
}
