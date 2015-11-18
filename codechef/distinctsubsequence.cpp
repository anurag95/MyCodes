#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, i;
	char str[1000];
	int dp[1000], sm[1003], last[130], *sum = sm + 2;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", str);
		n = strlen(str);
		dp[0] = 1;
		sum[0] = 1;
		for(i=0;i<130;i++)
			last[i] = -1;
		for(i=0;i<n;i++)
		{
			dp[i+1] = sum[i] - sum[last[str[i]]-1];
			sum[i+1] = sum[i]+dp[i+1];
			last[str[i]] = i+1;
		}
		printf("%d\n", sum[n]);
	}
	return 0;
}
