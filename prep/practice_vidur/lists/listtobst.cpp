#include <iostream>
using namespace std;

struct node
{
	int data;
	node *prev;
	node *next;
};

void print(node *head)
{
	node *ptr = head;
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void push(node **head, int data)
{
	node *temp = new node;
	temp->data = data;
	temp->next = *head;
	temp->prev = NULL;
	if((*head) != NULL)
		(*head)->prev = temp;
	*head = temp;
}

void preorder(node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->prev);
	preorder(root->next);
}

int count(node *head)
{
	node *ptr = head;
	int n = 0;
	while(ptr)
	{
		++n;
		ptr = ptr->next;
	}
	return n;
}

node *recurs(node **head, int n)
{
	if(n <= 0)
		return NULL;

	node *left = recurs(head, n/2);
	
	node *root = *head;
	root->prev = left;
	
	*head = (*head)->next;
	root->next = recurs(head, n-n/2-1);

	return root;
}

node *listtobst(node *head)
{
	int n = count(head);
	return recurs(&head, n);
}

int main()
{
	node *head = NULL;
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	print(head);

	node *root = listtobst(head);

	preorder(root);
	cout<<endl;
	return 0;
	return 0;
}