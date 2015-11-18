/*
Point to next higher in linked list
*/
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void push(node **head, int data)
{
	node *temp = new node;
	temp->data = data;
	temp->next = *head;
	(*head) = temp;
}

void print(node *head)
{
	node *temp = head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

node *sorted_merge(node *a, node *b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	node *result;
	if(a->data <= b->data)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return result;
}

void frontbacksplit(node *source, node **front_ref, node **back_ref)
{
	if (source == NULL || source->next == NULL)
	{
		*front_ref = source;
		*back_ref = NULL;
		return;
	}

	node *sptr = source;
	node *fptr = source->next;
	while(fptr &&  fptr->next && sptr)
	{
		fptr = fptr->next->next;
		sptr = sptr->next;
	}

	*front_ref = source;
	*back_ref = sptr->next;
	sptr->next = NULL;
}

void mergesort(node **head_ref)
{
	node *head = *head_ref;
	if(head == NULL || head->next == NULL)
		return;
	
	node *a, *b;
	frontbacksplit(head, &a, &b);

	mergesort(&a);
	mergesort(&b);

	*head_ref = sorted_merge(a, b);
}

int main()
{
	node *head = NULL;
	push(&head, 15);
	push(&head, 10);
	push(&head, 5);
	push(&head, 20);
	push(&head, 3);
	push(&head, 2);
	print(head);
	mergesort(&head);
	print(head);
	return 0;
}