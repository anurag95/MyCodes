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
	temp->next = (*head);
	(*head) = temp;
}

void print(node *ptr)
{
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void segregatelist(node **head)
{
	node *end = *head;
	while(end->next != NULL)
		end = end->next;

	node *new_end = end;
	node *curr = *head;

	while((curr->data)%2 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	node *prev = NULL;

	if((curr->data)%2 == 0)
	{
		*head = curr;
		while(curr != end)
		{
			if((curr->data)%2 == 0)
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				prev->next = curr->next;
				curr->next = NULL;
				new_end->next = curr;
				new_end = curr;
				curr = prev->next;
			}
		}
	}
	else
		prev = curr;

	if(new_end != end && (end->data)%2 != 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}

}

int main()
{
	node *head = NULL;
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	push(&head, 5);
	push(&head, 10);
	push(&head, 8);
	push(&head, 15);
	push(&head, 17);

	print(head);

	segregatelist(&head);

	print(head);
	return 0;
}