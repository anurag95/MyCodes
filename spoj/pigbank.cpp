#include<stdio.h>
#include<limits.h>
#define INF 10000
int main()
{
	long long int i, t, w, W, n, j;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld%lld%lld", &W, &w, &n);
		long long int dp[10020];
		for(i=0;i<10020;i++)
			dp[i] = INF;
		w-=W;
		long long int weight, value;
		while(n--)
		{
			scanf("%lld%lld", &value, &weight);
			if(dp[weight] > value)
			{
				dp[weight] = value;
			}
			for(j=0;j<=w - weight;j++)
			{
				if(dp[j+weight] > dp[j] + dp[weight])
					dp[j+weight] = dp[j] + dp[weight];
			}
		}
		if(dp[w]!=INF) printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[w]);
		else printf("This is impossible.\n");
	}
	return 0;
}
