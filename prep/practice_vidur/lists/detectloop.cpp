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

bool detectloop(node *head)
{
	node *ptr1 = head, *ptr2 = head;
	while(ptr1 && ptr2 && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if(ptr1 == ptr2)
			return 1;
	}
	return 0;
}

int main()
{
	node *head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);
	head->next->next->next->next = head;
	if(detectloop(head))
		cout<<"FOUND"<<endl;
	else
		cout<<"NOT FOUND"<<endl;
}