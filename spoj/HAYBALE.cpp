#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);

inline int inp()
{
	int noRead=0;
	char p=getchar_unlocked();
	for(;p<33;)
	{
		p=getchar_unlocked();
	};
	while(p>32)
	{
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	return noRead;
};

int arr[1000010], n, arr2[1000010];
int query(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += arr[idx];
		idx -= (idx&(-idx));
	}
	return sum;
}
void update(int idx, int val)
{
	for(; idx <= n; idx += (idx&(-idx)))
	{
		arr[idx] += val;
	}
}
void rangeupdate(int l, int r)
{
	update(l, 1);
	update(r, -1);
}
int main()
{
	int k, i, a, b	;
	n = inp();
	k = inp();
	memset(arr, 0, sizeof(arr));
	for(i=0;i<k;i++)
	{
		a = inp();
		b = inp();
		rangeupdate(a, b+1);
	}
	for(i=0;i<n+1;i++)
		arr2[i] = query(i);
	sort(arr2, arr2+n+1);
	printf("%d\n", arr2[n/2 + 1]);
	return 0;
}

