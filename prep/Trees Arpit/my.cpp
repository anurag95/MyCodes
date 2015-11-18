#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
struct node {
	int val;
	node* right;
	node* left;
};
void insert(node** root, int key)
{
	node *n = *root;
	if(!n){
		n = (node*)malloc(sizeof(node));
		n->val = key;
		n->left = n->right = NULL;
		root = &n;
	}
	else if(key > n->val)
		insert(&(n->right), key);
	else
		insert(&n->left, key);
	return ;
}
int main()
{
	node* r=NULL;
	insert(&r,10);
	insert(&r,20);
	insert(&r,8);
	insert(&r,4);
	insert(&r,9);
	insert(&r,25);
	if(!r)
		printf("Hey\n");
	printf("%d", r->val);
	return 0;
}

