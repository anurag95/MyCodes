#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* new_node(int x){
	node* temp = new node;
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* trim_leaves(node* root){
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL){
		delete root;
		return NULL;
	}
	root->left = trim_leaves(root->left);
	root->right = trim_leaves(root->right);
	return root;
}

void inord(node* root){
	if(root == NULL)
		return;
	inord(root->left);
	cout<<root->data<<" ";
	inord(root->right);
}

void preord(node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preord(root->left);
	preord(root->right);
}

void remove(node* root){
	if(root == NULL)
		return;
	remove(root->left);
	remove(root->right);
	delete root;
}

int main(){
	node* root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	cout<<"BEFORE TRIM"<<endl;
	inord(root);
	cout<<endl;
	preord(root);
	cout<<endl;
	trim_leaves(root);
	cout<<"AFTER TRIM"<<endl;
	inord(root);
	cout<<endl;
	preord(root);
	cout<<endl;
	
	remove(root);
	return 0;
}