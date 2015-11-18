/*
flatten multilevel linked list with child pointer
(used queue to implement)
*/
#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *next;
	node *child;
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

node *createlist(int *arr, int n)
{
	node *head = NULL;
	node *ptr = NULL;
	for (int i = 0; i < n; ++i)
	{
		if(!head)
			head = ptr = new node;
		else
		{
			ptr->next = new node;
			ptr = ptr->next;
		}
		ptr->data = arr[i];
		ptr->next = ptr->child = NULL;
	}
	return head;
}

void flatten(node *head)
{
	queue <node*> Q;
	Q.push(head);
	node *tail = NULL;
	while(!Q.empty())
	{
		node *curr = Q.front();
		Q.pop();
		node *ptr = curr;
		if(tail)
			tail->next = ptr;
		while(ptr)
		{
			if(ptr->child)
			{
				Q.push(ptr->child);
				ptr->child = NULL;
			}
			tail = ptr;
			ptr = ptr->next;
		}
	}
}

int main()
{
	int arr1[] = {10, 5, 12, 7, 11};
	int arr2[] = {4, 20, 13};
	int arr3[] = {17, 6};
	int arr4[] = {9, 8};
	int arr5[] = {19, 15};
	int arr6[] = {2};
	int arr7[] = {16};
	int arr8[] = {3};
	node *head1 = createlist(arr1, 5);
	node *head2 = createlist(arr2, 3);
	node *head3 = createlist(arr3, 2);
	node *head4 = createlist(arr4, 2);
	node *head5 = createlist(arr5, 2);
	node *head6 = createlist(arr6, 1);
	node *head7 = createlist(arr7, 1);
	node *head8 = createlist(arr8, 1);
	
	head1->child = head2;
	head1->next->next->next->child = head3;
	head3->child = head4;
	head4->child = head5;
	head2->next->child = head6;
	head2->next->next->child = head7;
	head7->child = head8;

	flatten(head1);
	print(head1);
	return 0;
}