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
vector<int> adj[1000];
int visited[1000] = {0};
void dfs(int ind)
{
	for(int i=0;i<adj[ind].size();i++)
	{
		if(visited[adj[ind][i]] == 0){
			visited[adj[ind][i]] = 1;
			dfs(adj[ind][i]);
		}
	}
}
int main()
{
	int arr[1000];
	fill(arr, arr+1000, 4);
	printf("%d ", arr[5]);
	int t;
	si(t)
	while(t--)
	{

	}
	return 0;
}

