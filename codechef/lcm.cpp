#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pb push_back
void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
vector<int> sieve[1000010];
int vis[1000010];
void makesieve()
{
	memset(vis, 0, sizeof(vis));
	for(int i=2;i<1000010;i++)
	{
		if(vis[i])
			continue;
		sieve[i].pb(i);
		for(int j = 2*i;j<1000010;j+=i)
		{
			vis[i] = 1;
			sieve[j].pb(i);
		}
	}
}
int main()
{
	int t, n, i;
	makesieve();
	scanint(t);
	while(t--)
	{
		scanint(n);
		int factors[1000010], last[100010];
		memset(factors, -1, sizeof(factors));
		memset(last, -1, sizeof(last));
		int var;
		int ans = INT_MIN;
		for(i=0;i<n;i++)
		{
			scanint(var);
			for(int j=0;j<sieve[var].size();j++)
			{
				last[i] = max(last[i], factors[sieve[var][j]]);
				factors[sieve[var][j]] = i;
			}
		}
//		for(i=0;i<n;i++)
//			printf("%d ", last[i]);
//		printf("\n");
		int dp[100010];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=1;i<n;i++)
		{
			if(i-last[i]>dp[i-1])
				dp[i] = 1+dp[i-1];
			else dp[i] = i-last[i];
			ans = max(ans, dp[i]);
		}
		if(ans > 1)
			printf("%d\n", ans);
		else    printf("-1\n");
	}
	return 0;
}
