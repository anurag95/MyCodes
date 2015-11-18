#include<bits/stdc++.h>
using namespace std;
int dp[20010][501];
int main()
{
	char str[20010];
	int m, l, q, len, i, j;
	scanf("%s", str);
	scanf("%d", &q);
	len = strlen(str);
	while(q--)
	{
		int ans = 0;
		scanf("%d %d", &m ,&l);
	//	for(i=0;i<=len;i++)
	//		for(j=0;j<=m;j++)
	//			dp[i][j] = 0;
		memset(dp, 0, sizeof(dp));
		for(i=1;i<=len;i++)
		{
			for(j=0;j<m;j++)
			{
				dp[i][(j*10 + str[i-1]-'0')%m] += dp[i-1][j];
			}
			dp[i][(str[i-1]-'0')%m]++; 
			ans += dp[i][l];
		}
		printf("%d\n", ans);
	}
	return 0;
}

