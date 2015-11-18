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

void remove_loop(node *ptr, node *head)
{
	node *ptr1 = ptr, *ptr2 = ptr;
	int k = 1;
	while(ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		++k;
	}
	ptr1 = head;

	ptr2 = head;
	for (int i = 0; i < k; ++i)
		ptr2 = ptr2->next;

	while(ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	ptr2 = ptr2->next;
	while(ptr2->next != ptr1)
		ptr2 = ptr2->next;
	ptr2->next = NULL;
}

bool detect_remove_loop(node *head)
{
	node *ptr1 = head, *ptr2 = head;
	while(ptr1 && ptr2 && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if(ptr1 == ptr2)
		{
			remove_loop(ptr1, head);
			return 1;
		}
	}
	return 0;
}

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

int main()
{
	node *head = NULL;
	push(&head, 10);
	push(&head, 4);
	push(&head, 25);
	push(&head, 20);
	push(&head, 50);
	head->next->next->next->next->next = head->next->next;
	if(detect_remove_loop(head))
	{
		cout<<"FOUND"<<endl;
		print(head);
	}
	else
		cout<<"NOT FOUND"<<endl;
}