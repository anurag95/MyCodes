#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};


void middle(node *head)
{
	node *ptr1 = head;
	node *ptr2 = head;
	while(ptr1 && ptr2 && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	cout<<ptr1->data<<endl;
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
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	push(&head, 0);
	print(head);
	middle(head);
	return 0;
}