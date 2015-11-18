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
	node* children[26];
};

char str[1000010];

int add(node* head) {
	int level=0;
	int count = 0;
	node* crawl = head;
	for(level=0;str[level]!='\0';level++)
	{
		if((crawl->children[str[level]-'a']) != NULL)
		{
			crawl = crawl->children[str[level]-'a'];
			count++;
		}
		else {
			crawl->children[str[level]-'a'] = new node;
			crawl = crawl->children[str[level]-'a'];
	for(int i=0;i<26;i++)
				crawl->children[i] = NULL;
		} 
	}
	count++;
	return min(level, count);
}

int main()
{
	int t, n, c=0;
	ll res;
	si(t)
	while(t--)
	{
		node* head = new node;
		res = 0;
		for(int i=0;i<26;i++)
			head->children[i] = NULL;
		c++;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%s", str);
			res += (ll)add(head);
		}
		printf("Case #%d: %lld\n", c, res);
	}
	return 0;
}

