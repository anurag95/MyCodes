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
map<int, int> numcnt, gcdcnt;
int gcd(int a, int b)
{
	int r;
	while(b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int n, i, j;
	int table[250001];
	int ans[501];
	si(n)
	for(i=0;i<n*n;i++)
	{
		si(table[i]);
		if(numcnt.find(table[i]) != numcnt.end())
			numcnt[table[i]]++;
		else numcnt[table[i]]=1;
		gcdcnt[table[i]]=0;
	}
	int id = n-1;
	sort(table, table+n*n);
	for(i=n*n-1;i>=0;i--)
	{
		int var = numcnt[table[i]];
		if(var > gcdcnt[table[i]])
		{
			ans[id] = table[i];
			gcdcnt[table[i]]++;
			for(int k=id+1;k<n;k++)
			{
				gcdcnt[gcd(table[i], ans[k])] += 2;
			}
			id--;
			if(id == -1)
				break;
		}
	}
	for(i=0;i<n-1;i++)
		printf("%d ", ans[i]);
	pi(ans[n-1]);
	return 0;
}

