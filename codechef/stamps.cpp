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
int n, m, k[22], arr[22][20010], id[22];
int func(int person, int mask)
{
	if(person == m)
		return 0;
	int res = func(person+1, mask);
	if((mask>>person) & 1)
		return res;
	int res2 = func(person+1, mask|id[person]);
	if(res2+1 > res)
	{
		return res2+1;
	}
	return res;
}
int main()
{
	int i, j, mask;
	scanf("%d%d", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%d", &k[i]);
		for(j=0;j<k[i];j++)
			scanf("%d", &arr[i][j]);
	}
	for(i=1;i<20001;i++)
	{
		mask = 0;
		for(j=0;j<m;j++)
		{
			if(binary_search(arr[j], arr[j]+k[j], i))
				mask |= (1<<j);
		}
		for(j=0;j<m;j++)
		{
			if(binary_search(arr[j], arr[j]+k[j], i))
				id[j] |= mask;
		}
	}
	printf("%d\n", func(0, 0));
	return 0;
}

