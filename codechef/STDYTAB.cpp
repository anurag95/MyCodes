#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000000
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
ll dp[4005][4005];
ll ans[4005][4005];
ll value[4005];
int main()
{
	memset(dp, 0, sizeof(dp));
	ll t, n, m, i, j;
	for(i=0;i<4005;i++)
		dp[i][0] = 1LL;
	for(i=1;i<4005;i++){
		for(j=1;j<=i;j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
		}
	}
/*	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
*/	scanf("%lld", &t);
	while(t--)
	{
		sll(n);
		sll(m);
		memset(ans, 0, sizeof(0));
		memset(value, 0, sizeof(0));
		for(i=0;i<=m;i++)
		{
			value[i] = dp[i+m-1][m-1];
			ans[0][i] = dp[i+m-1][m-1];
		}
		ll sum;
		for(i=1;i<n;i++)
		{
			sum = 0;
			for(j=0;j<=m;j++)
			{
				sum = (sum+ans[i-1][j])%mod;
				ans[i][j] = (value[j]*sum)%mod;
			}
		}
/*		for(i=0;i<n;i++)
		{
			for(j=0;j<=m;j++)
			{
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
*/
		sum = 0LL;
		for(i=0;i<=m;i++)
			sum = (sum+ans[n-1][i])%mod;
		printf("%lld\n", sum);
	}
	return 0;
}
