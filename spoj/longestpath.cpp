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
int total=0, n, visited[10010]={0};
vector<int>vec[10010];
int dfs(int node)
{
	int i, flag=0;
	int m, max1=-1, max2=-1;
	visited[node] = 1;
	for(i=0;i<vec[node].size();i++)
	{
		if(visited[vec[node][i]] == 0)
		{
			m = dfs(vec[node][i]);
			if(m>=max1){
				max2=max1;
				max1=m;
			}
			else if(m>max2)
				max2=m;
		}
	}
	total = max(total, max1+max2+2);
	return (max1+1);
}
int main()
{
	int i, u, v;
	si(n)
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d", &u, &v);
		vec[u].pb(v);
		vec[v].pb(u);
	}
	dfs(1);
	printf("%d\n", total);
	return 0;
}

