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
int m;
int n;
vector<int> vec[20010];
bool bfs()
{
	int i, visited[20010] = {0};
	queue<int>q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty())
	{
		int var = q.front();
		q.pop();
		for(i=0;i<vec[var].size();i++)
		{
			if(!(visited[vec[var][i]]))
			{	
				q.push(vec[var][i]);
				visited[vec[var][i]] = 1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i] == 0)
			return false;
	}
	return true;
}
int main()
{
	si(n)
	si(m)
	int i, u, v;
	for(i=0;i<m;i++)
	{
		scanf("%d%d", &u, &v);
		vec[u].pb(v);
		vec[v].pb(u);
	}
	if(m!=(n-1))
		printf("NO\n");
	else {
		if(bfs())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

