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
int mini, maxi, n, var, want, anu, k, king, visited[10002], dist[10002], product[10002];
vector<int> cities[10002];
void dfs(int cit, int pass)
{
	int i;
	if(product[cit] == want)
	{
		if(!pass)
		{
			if(maxi < dist[cit])
			{
				anu = cit;
				maxi = dist[cit];
			}
		}
		else {
			if(mini > cit)
				mini = cit;
		}
	}
//	printf("size %ld\n", cities[cit].size());
	for(i=0;i<cities[cit].size();i++)
	{
		if(visited[cities[cit][i]] != 1)
		{
			visited[cities[cit][i]] = 1;
			if(cities[cit][i] == king)
				pass=1;
			dfs(cities[cit][i], pass);
			if(cities[cit][i] == king)
				pass=0;
			visited[cities[cit][i]] = 0;
		}
	}
}
int main()
{
	int i;
	int u, v;
	memset(visited, 0,10002);
	memset(dist, 0, 10002);
	scanf("%d%d", &n, &k);
	scanf("%d", &king);
	visited[king] = 1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d", &u, &v);
		cities[u].pb(v);
		cities[v].pb(u);
	}
	queue<int> q;
	q.push(king);
	int cit;
	while(!q.empty())
	{	
		cit = q.front();
		q.pop();
		for(i=0;i<cities[cit].size();i++)
		{
			if(visited[cities[cit][i]]!=1)
			{
				visited[cities[cit][i]] = 1;
				dist[cities[cit][i]] = dist[cit]+1;
				q.push(cities[cit][i]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d", &var);
		product[i] = var;
	}
	int query, pass;
	scanf("%d", &query);
	int arr[102][10002];
//	for(i=1;i<=n;i++)
//		printf("%d\n", dist[i]);
	int j;
	for(i=1;i<=k;i++)
	{
		want = i;
		for(j=1;j<=n;j++)
		{
			if(j == king)
				pass = 1;
			else pass = 0; 
			mini = 5000;
			maxi = -1;
			memset(visited, 0, n+1);
			visited[j] = 1;
			dfs(j, pass);
			if(maxi > -1)
				arr[i][j] = anu;
			else arr[i][j] = mini;
		}
	}
	while(query--)
	{
		scanf("%d%d", &cit, &want);
		printf("%d\n", arr[want][cit]);
	}
	return 0;
}
