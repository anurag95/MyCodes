#include<bits/stdc++.h>
using namespace std;
char str1[100010];
char str2[100010];
int main()
{
	int t, a, b, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", str1);
		scanf("%s", str2);
		scanf("%d%d%d", &a, &b, &k);
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		if(a == 0)
		{
			printf("0\n");
			continue;
		}
		if(a*abs(len1-len2)>k)
		{
			printf("-1\n");
			continue;
		}
		if(b == 0)
		{
			if(k >= a*abs(len1-len2))
				printf("%d\n", a*abs(len1-len2));
			else printf("-1\n");
			continue;
		}
		int dp[2][100010];
		int d1,d2,d3,i,j;
		int up=0, down=1, start=1, end=min(k+1, len2);
		for(i=0;i<=k && i<=len2;i++)
			dp[0][i] = a*i;
		for(i=1;i<=len1;i++)
		{
			dp[down][0] = i*a;
			if(start > 1)
				dp[down][start-1] = 1000;
			dp[up][end] = 1000;
			for(j=start;j<=end && j<=len2;j++)
			{
				d1=((str1[i-1]==str2[j-1])?0:b)+dp[up][j-1];
				d2 = dp[down][j-1]+a; 
				d3 = dp[up][j]+a;
				dp[down][j] = min(d1, min(d2, d3));
			}
			if(end < len2)
				end++;
			if(i>k && start<(len2-k-2))
				start++;
			up = (up+1)%2;
			down = (down+1)%2;
		}
		if(dp[up][len2] > k)
			printf("-1\n");
		else
			printf("%d\n", dp[up][len2]);
	}
	return 0;
}
