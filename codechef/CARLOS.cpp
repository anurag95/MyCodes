#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
#define mymin(a, b) (a<b)?a:b
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanint(x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
int dp[200010][203], visited[203], trans[204][204];;
//arr[200010];
//struct node {
int par[204];
int rank[204];
//}parent[204];
int find(int a)
{
	if(par[a] != a)
		par[a] = find(par[a]);
	return par[a];
}
void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if(x == y)
		return ;
	if(rank[x] < rank[y])
		par[x] = y;
	else if(rank[y] < rank[x])
		par[y] = x;
	else {
		par[y] = x;
		rank[x]++;
	}
}
int main()
{
	int t, m, n, k, i, j, x, y, mini, var;
	for(i=0;i<=200000;i++)
		dp[i][0] = 200010;
	for(i=0;i<=200;i++)
		dp[0][i] = 0;
	si(t);
	while(t--)
	{
		sii(m, k);
		si(n);
		//		memset(trans, 0, sizeof(trans));
		for(i=0;i<=m;i++){
			par[i] = i;
			rank[i] = 0;
		}
		for(i=0;i<k;i++)
		{
			sii(x, y)
			uni(x, y);
		}
		//		for(i=1;i<=n;i++)
		//			scanf("%d", &arr[i]);

		for(i=1;i<=m;i++){
			for(j=1;j<=m;j++)
				trans[i][j] = (find(i) == find(j))?1:0;
		}
		for(i=1;i<=n;i++)
		{
			si(var);
			for(j=1;j<=m;j++)
			{
				if(var == j)
				{
					dp[i][j] = mymin(dp[i-1][j], dp[i][j-1]);
				}
				else if(trans[var][j]) {
					dp[i][j] = mymin(dp[i-1][j]+1, dp[i][j-1]);
				}
				else {
					dp[i][j] = dp[i][j-1];
				}
			}
		}
		mini = dp[n][m];
		if(mini >= 200010)
			printf("-1\n");
		else 
			printf("%d\n", mini);
	}
	return 0;
}

/*


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
int dp[200010][203], trans[203][203], visited[203], arr[200010], var, m;
void dfs(int n)
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(visited[i] == 0 && (trans[i][n] == 1))
		{
			visited[i] = 1;
			trans[i][var] = trans[var][i] = 1;
			dfs(i);
		}
	}
}
int main()
{
	int t, n, k, i, j, x, y, var;
	for(i=0;i<=200000;i++)
		dp[i][0] = 200010;
	for(i=0;i<=200;i++)
		dp[0][i] = 0;
	si(t)
	while(t--)
	{
		sii(m, k);
		si(n);
		memset(trans, 0, sizeof(trans));
		for(i=1;i<=m;i++)
			trans[i][i] = 1;
		for(i=0;i<k;i++)
		{
			scanf("%d%d", &x, &y);
			trans[x][y] = trans[y][x] = 1;
		}
		for(i=1;i<=m;i++)
		{
			memset(visited, 0, sizeof(visited));
			var = i;
			visited[var] = 1;
			dfs(i);
		}
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
				else if(trans[arr[i]][j] == 1) {
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
*/
