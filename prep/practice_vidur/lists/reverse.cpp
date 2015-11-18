#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void rev_ite(node **head)
{
	node *prev = NULL;
	node *curr = *head;
	node *next;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void rev_rec(node **head)
{
	if(*head == NULL)
		return;
	node *first = *head;
	node *rest = first->next;
	
	if(rest == NULL)
		return;

	rev_rec(&rest);

	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

void push(node **head, int data)
{
	node *temp = new node;
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void print(node *head)
{
	node *curr = head;
	while(curr)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int main()
{
	node *head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15); 
	push(&head, 85);
	
	print(head);
	//rev_ite(&head);
	rev_rec(&head);
	print(head);
	
	return 0;
}