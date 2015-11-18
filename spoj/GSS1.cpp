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
int n, arr[50005];
struct node {
	int sum, pre, suf, max;
}segtree[200000];

node merge(node left, node right)
{
	node cur;
	cur.sum = left.sum+right.sum;
	cur.pre = max(left.pre, left.sum+right.pre);
	cur.suf = max(left.suf+right.sum, right.suf);
	cur.max = max(cur.pre, max(cur.suf, max(left.max, max(right.max, left.suf + right.pre))));
	return cur;
}

void create(int start, int end, int cur)
{
	if(start == end)
	{
		segtree[cur].sum = arr[start];
		segtree[cur].pre = arr[start];
		segtree[cur].suf = arr[start];
		segtree[cur].max = arr[start];
		return ;
	}
	int mid = (start+end)/2;
	int left = 2*cur+1, right = 2*cur+2;
	create(start, mid, 2*cur + 1);
	create(mid+1, end, 2*cur + 2);
	segtree[cur] = merge(segtree[left], segtree[right]);
}
node getsum(int start, int end, int l, int r, int index)
{
	if(l==start && r==end)
		return segtree[index];
	int mid = (start+end)/2;
	if(l>mid)
		return getsum(mid+1, end, l, r, 2*index+2);
	if(r<=mid)
		return getsum(start, mid, l, r, 2*index+1);
	node left = getsum(start, mid, l, r, 2*index+1); 
	node right = getsum(mid+1, end, l, r, 2*index+2);
	node result = merge(left, right);
	return result;
}

/*
void update(int start, int end, int i, int diff, int index)
{
	if(i<start || i>end)
		return ;
	segtree[index] += diff;
	if(start != end)
	{
		int mid = (start+end)/2;
		update(start, mid, i, diff, 2*index+1);
		update(mid+1, end, i, diff, 2*index+2);
	}
	return ;
}
*/

int main()
{
	int i, q, n;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	create(0, n-1, 0);
//	for(i=0;i<15;i++)
//		printf("%d ", segtree[i]);
	scanf("%d", &q);
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);	
		node sum = getsum(0, n-1, l, r, 0);
		printf("%d\n", sum.max);
	}
	return 0;
}

