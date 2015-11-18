// point of intersection of 2 lists
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

int count(node *head)
{
	int n = 0;
	node *ptr = head;
	while(ptr)
	{
		ptr = ptr->next;
		++n;
	}
	return n;
}

node *new_node(int data)
{
	node *ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}


int func(int d, node *head1, node *head2)
{
	node *ptr1 = head1;
	node *ptr2 = head2;
	for (int i = 0; i < d; ++i)
	{
		if(ptr1 == NULL)
			return -1;
		ptr1 = ptr1->next;
	}

	while(ptr1 && ptr2)
	{
		if(ptr1 == ptr2)
			return ptr1->data;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return -1;
}

int IntesectionNode(node *head1, node *head2)
{
	int n1 = count(head1);
	int n2 = count(head2);

	if(n1 > n2)
		return func(n1-n2, head1, head2);
	else
		return func(n2-n1, head2, head1);
}

int main()
{
	node *head1 = NULL, *head2 = NULL;
	head1 = new_node(10);
	
	head2 = new_node(3);
	head2->next = new_node(6);
	head2->next->next = new_node(9);

	head1->next = new_node(15);
	head2->next->next->next = head1->next;
	head1->next->next = new_node(30);
	head1->next->next->next = NULL;
	
	cout<<IntesectionNode(head1, head2)<<endl;
	return 0;
}