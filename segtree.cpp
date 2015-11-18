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
int n, arr[100], segtree[200];
int create(int start, int end, int cur)
{
	if(start == end)
	{
		segtree[cur] = arr[start];
		return arr[start];
	}
	int mid = (start+end)/2;
	segtree[cur] = create(start, mid, 2*cur + 1) + create(mid+1, end, 2*cur + 2);
	return segtree[cur];
}
int getsum(int start, int end, int l, int r, int index)
{
	if(l<=start && r>=end)
		return segtree[index];
	if(l>end || r<start)
		return 0;
	int mid = (start+end)/2;
	return getsum(start, mid, l, r, 2*index+1) + getsum(mid+1, end, l, r, 2*index+2);
}
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
int main()
{
	int i, q, m, t;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d", &arr[i]);
		create(0, n-1, 0);
		for(i=0;i<15;i++)
			printf("%d ", segtree[i]);
//		scanf("%d", &m);
//		while(m--)
//		{
		int val, ind;
		scanf("%d%d", &ind, &val);
		update(0, n-1, ind, val-arr[ind], 0);
		for(i=0;i<15;i++)
			printf("%d ", segtree[i]);
			int l, r;
		    scanf("%d%d", &l, &r);	
			int sum = getsum(0, n-1, l, r, 0);
			printf("%d\n", sum);
//		}
	}
	return 0;
}
