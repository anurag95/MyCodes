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
int parent[100010];
int find(int u)
{
	if(parent[u] != u)
		parent[u] = find(parent[u]);
	return parent[u];
}
int main()
{
	int t,i, r,a,b,n;
	si(t)
	while(t--)
	{
		si(n);
		si(r);
		for(i=0;i<n;i++)
			parent[i] = i;
		for(i=0;i<r;i++)
		{
			sii(a, b);
			int u = find(a), w = find(b);
			if(u!=w)
			{
				parent[u] = parent[w];
			}
		}
		for(i=0;i<n;i++)
			find(i);
		set<int> S;
		for(i=0;i<n;i++)
			S.insert(parent[i]);
		printf("%d\n", (int)S.size());
	}
	return 0;
}

