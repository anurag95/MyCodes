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

void print_kdistdown(node* root, int k){
	if(root == NULL)
		return;
	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	print_kdistdown(root->left, k - 1);
	print_kdistdown(root->right, k - 1);
}

int print_kdistnode(node* root, node* target, int k){
	if(root == NULL)
		return -1;
	if(root == target){
		print_kdistdown(root, k);
		return 0;
	}
	
	int dl = print_kdistnode(root->left, target, k);
	if(dl != -1){
		if(dl + 1 == k)
			cout<<root->data<<" ";
		else
			print_kdistdown(root->right, k-dl-2);
		return dl + 1;
	}

	int dr = print_kdistnode(root->right, target, k);
	if(dr != -1){
		if(dr + 1 == k)
			cout<<root->data<<" ";
		else
			print_kdistdown(root->left, k-dr-2);
		return dr + 1;
	}

	return -1;
}

void print(node* root){
	if(root == NULL)
		return;
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}

void remove(node* root){
	if(root == NULL)
		return;
	remove(root->left);
	remove(root->right);
	delete root;
}

int main(){
	node* root = new_node(20);
	root->left = new_node(8);
	root->right = new_node(22);
	root->left->left = new_node(4);
	root->left->right = new_node(12);
	root->left->right->left = new_node(10);
	root->left->right->right = new_node(14);
	node *target = root->left->right;
	int k = 2;
	print(root);
	cout<<endl;
	print_kdistnode(root, target, k);
	cout<<endl;
	remove(root);
	return 0;
}