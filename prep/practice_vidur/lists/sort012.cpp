#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node* new_node(int x){
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void push(node **head, int x){
	node *temp = new node;
	temp->data = x;
	temp->next = (*head);
	(*head) = temp;
}

void print(node *node){
	while(node != NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
	return;
}

void sort(node *head){
	int count[] = {0, 0, 0};
	node *ptr = head;
	while(ptr != NULL){
		++count[ptr->data];
		ptr = ptr->next;
	}
	int i = 0;
	ptr = head;
	while(ptr != NULL){
		if(count[i]){
			ptr->data = i;
			--count[i];
			ptr = ptr->next;
		}
		else
			++i;
	}
}

int main(){
	int n;
	cin>>n;
	node *head = NULL;

	for (int i = 0; i < n; ++i){
		int x;
		cin>>x;
		push(&head, x);
	}
	print(head);
	cout<<endl;
	sort(head);
	print(head);
	cout<<endl;
	return 0;
}