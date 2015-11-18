/*
LCS
*/
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
int dp[5001][5001] = {0};
int main()
{
	char a[5001], b[5001];
	scanf("%s", a);
	scanf("%s", b);
	int len = strlen(a);
	int i, j;
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len;j++)
		{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(a[i-1] == b[j-1])
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
		}
	}
	printf("%d\n", dp[len][len]);
	return 0;
}

