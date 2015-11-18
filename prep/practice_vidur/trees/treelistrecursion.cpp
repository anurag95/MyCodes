#include <iostream>
#include <stddef.h>
#include <stdlib.h>
using namespace std;

/* The node type from which both the tree and list are built */
struct node
{
	int data;
	node* small;
	node* large;
};




/*
 helper function -- given two list nodes, join them
 together so the second immediately follow the first.
 Sets the .next of the first and the .previous of the second.
*/
void join(node *a, node *b)
{
	a->large = b;
	b->small = a;
}


/*
 helper function -- given two circular doubly linked
 lists, append them and return the new list.
*/
node *append(node *a, node *b)
{
	node *aLast, *bLast;
	
	if (a == NULL)
		return b;
	if (b == NULL)
		return a ;
	
	aLast = a->small;
	bLast = b->small;
	
	join(aLast, b);
	join(bLast, a);
	
	return(a);
}


/*
 --Recursion--
 Given an ordered binary tree, recursively change it into
 a circular doubly linked list which is returned.
*/
node *treeToList(node *root)
{
	node *aList, *bList;
	
	if (root==NULL) 
		return NULL;

	/* recursively solve subtrees */
	aList = treeToList(root->small);
	bList = treeToList(root->large);
	
	/* Make a length-1 list ouf of the root */
	root->small = root;
	root->large = root;

	/* Append everything together in sorted order */
	aList = append(aList, root);
	aList = append(aList, bList);
	
	return aList ;
}


node *new_node(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->small = NULL;
	temp->large = NULL;
	return temp ;
}

void tree_insert(node **rootRef, int data)
{
	node *root = *rootRef;
	if (root == NULL)
		*rootRef = new_node(data);
	else
	{
		if (data <= root->data)
			tree_insert(&(root->small), data);
		else 
			tree_insert(&(root->large), data);
	}
}


void print(node* head)
{
	node *current = head;
	
	while(current != NULL)
	{
		cout<<current->data<<" ";
		current = current->large;
		if (current == head)
			break;
	}
	cout<<endl;
}


/* Demo that the code works */
int main()
{
	node *root = NULL;
	node *head;
	
	tree_insert(&root, 4);
	tree_insert(&root, 2);
	tree_insert(&root, 1);
	tree_insert(&root, 3);
	tree_insert(&root, 5);
	
	head = treeToList(root);
	
	print(head);    /* prints: 1 2 3 4 5  */
	
	return(0);
}