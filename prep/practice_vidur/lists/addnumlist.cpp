/*
Add 2 nums represented by a linked list.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int data;
	node *next;
};

void push(node **head, int data){
	node *temp = new node;
	temp->data = data;
	temp->next = (*head);
	(*head) = temp;
}

int size(node *ptr){
	int size = 0;
	while(ptr != NULL){
		++size;
		ptr = ptr->next;
	}
	return size;
}

void print(node *ptr){
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

node* add_same_size(node *head1, node *head2, int *carry){
	if(head1 == NULL)
		return NULL;

	node *result = new node;
	result->next = add_same_size(head1->next, head2->next, carry);

	int sum = head1->data + head2->data + (*carry);
	*carry = sum/10;
	sum %= 10;
	result->data = sum;

	return result;
}

void add_remaining(node *head1, node *ptr, int *carry, node**result){
	if(head1 != ptr){
		add_remaining(head1->next, ptr, carry, result);

		int sum = head1->data + (*carry);
		*carry = sum/10;
		sum %= 10;

		push(result, sum);
	}
}

void add_list(node *head1, node*head2, node **result){
	if(head1 == NULL){
		*result = head2;
		return;
	}

	if(head2 == NULL){
		*result = head1;
		return;
	}

	int size1 = size(head1);
	int size2 = size(head2);
	int carry = 0;

	if(size1 == size2)
		*result = add_same_size(head1, head2, &carry);
	else{
		int diff = abs(size1 - size2);

		if(size1 < size2)
			swap(head1, head2);
		
		node *ptr = NULL;
		for (ptr = head1; diff--; ptr = ptr->next);

		*result = add_same_size(ptr, head2, &carry);

		add_remaining(head1, ptr, &carry, result);
	}

	if(carry)
		push(result, carry);
}

int main(){
	node *head1 = NULL, *head2 = NULL, *result = NULL;
	
	int arr1[] = {2, 2, 2};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	for (int i = n - 1; i >= 0; --i)
		push(&head1, arr1[i]);
	
	int arr2[] = {1, 8, 1, 1, 1};
	int m = sizeof(arr2)/sizeof(arr2[0]);
	for (int i = m - 1; i >= 0; --i)
		push(&head2, arr2[i]);
	
	add_list(head1, head2, &result);
	print(result);
	return 0;
}