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
vector < pair <int, pair <int, int> > > edge;
int parent[10001];
int find(int u)
{
	if(u!=parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main()
{
	int t, i, n, j, num, a, wt;
	char name[20];
	si(t);
	while(t--)
	{
		edge.clear();
		si(n);
		for(i=1;i<=n;i++)
		{
			parent[i] = i;
			scanf("%s", name);
			si(num);
			for(j=0;j<num;j++){
				sii(a, wt);
				if(a>i)
					edge.push_back(make_pair(wt, make_pair(i, a)));
			}
		}
		sort(edge.begin(), edge.end());
		int u, v, sum = 0, sz = edge.size();
		for(i=0;i<sz;i++)
		{
			u = find(edge[i].second.first);
			v = find(edge[i].second.second);
			wt = edge[i].first;
			if(u!=v)
			{
				sum += wt;
				parent[u] = parent[v];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
