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
int dp[200010][203], visited[203], arr[200010];
struct node {
	int par;
	int rank;
}parent[204];
//int trans[203][203];
int find(int a)
{
	if(parent[a].par != a)
		parent[a].par = find(parent[a].par);
	return parent[a].par;
}
void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if(x == y)
		return ;
	if(parent[x].rank < parent[y].rank)
		parent[x].par = y;
	else if(parent[y].rank < parent[x].rank)
		parent[y].par = x;
	else {
		parent[y].par = x;
		parent[x].rank++;
	}
}
int main()
{
	int t, m, n, k, i, j, x, y, var;
	si(t)
		while(t--)
		{
			sii(m, k);
			si(n);
			//		memset(trans, 0, sizeof(trans));
			for(i=0;i<=m;i++){
				parent[i].par = i;
				parent[i].rank = 0;
			}
			//		for(i=1;i<=m;i++)
			//			trans[i][i] = 1;
			for(i=0;i<k;i++)
			{
				scanf("%d%d", &x, &y);
				//			trans[x][y] = trans[y][x] = 1;
				//	int p1 = find(x);
				//	int p2 = find(y);
				uni(x, y);
			}
			/*
			   for(i=1;i<=m;i++)
			   {
			   memset(visited, 0, sizeof(visited));
			   visited[i] = 1;
			   queue<int> q;
			   q.push(i);
			   while(!q.empty())
			   {
			   var = q.front();
			   q.pop();
			   visited[var] = 1;
			   for(j=1;j<=m;j++)
			   if(visited[j] == 0 && trans[var][j])
			   {
			   q.push(j);
			   trans[i][j] = trans[j][i] = 1;
			   }
			   }
			   }
			 */
			for(i=1;i<=n;i++)
				scanf("%d", &arr[i]);
			for(i=0;i<=n;i++)
				dp[i][0] = 200010;
			for(i=0;i<=m;i++)
				dp[0][i] = 0;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					if(arr[i] == j)
					{
						dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
					}
					else if(find(arr[i]) == find(j)) {
						dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]);
					}
					else {
						dp[i][j] = dp[i][j-1];
					}
				}
			}
			int mini = dp[n][m];
			if(mini >= 200010)
				printf("-1\n");
			else 
				printf("%d\n", mini);
		}
	return 0;
}

