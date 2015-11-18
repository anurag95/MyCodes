#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *reverse(node *head, int k)
{
	node *curr = head;
	node *next = NULL;
	node *prev = NULL;
	int cnt = 0;

	while(curr && cnt < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}
	if(next != NULL)
		head->next = reverse(next, k);
	return prev;
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
	push(&head, 8);
	push(&head, 7);
	push(&head, 6); 
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	print(head);
	head = reverse(head, 2);
	print(head);
	
	return 0;
}