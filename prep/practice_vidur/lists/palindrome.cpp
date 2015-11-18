/*
check whether list a palindrome
*/
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void reverse(node **head)
{
	node *prev = NULL;
	node *curr = *head;
	node *next = NULL;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

bool compare(node *head1, node *head2)
{
	node *ptr1 = head1;
	node *ptr2 = head2;

	while(ptr1 && ptr2)
	{
		if(ptr1->data != ptr2->data)
			return 0;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return 1;
}

bool palin(node *head)
{
	node *sptr = head;
	
	if(sptr == NULL || sptr->next == NULL)
		return true;

	node *fptr = head;
	node *prev_sptr = head;
	node *mid = NULL;

	bool res = true;
	while(fptr && fptr->next)
	{
		fptr = fptr->next->next;
		prev_sptr = sptr;
		sptr = sptr->next;
	}

	if(fptr != NULL)	//odd number of elements in the list
	{
		mid = sptr;
		sptr = sptr->next;
	}

	node *second_half = sptr;
	prev_sptr->next = NULL;
	reverse(&second_half);
	res = compare(head, second_half);

	reverse(&second_half);
	if(mid != NULL)	//odd number of elements in the list
	{
		prev_sptr->next = mid;
		mid->next = second_half;
	}
	else
		prev_sptr->next = second_half;

	return res;
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
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	print(head);
	if(palin(head))
		cout<<"Is Palindrome"<<endl;
	else
		cout<<"Is Not Palindrome"<<endl;
	print(head);
	return 0;
}