#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, c, k, i, j, l, r, o;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n, &c, &k);
		double dp[51][51][101] = {0};
		for(i=1;i<=n;i++)
			dp[0][i][1] = 1;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d", &l, &r);
			for(j=1;j<=n;j++)
			{
				for(o=0;o<c;o++)
				{
					if(j>=l && j<=r)
					{
						for(int m=0;m<c;m++)
							dp[i][j][(o*m)%c] += dp[i-1][j][o]/(2*c);
						dp[i][j][o] += dp[i-1][j][o]/2;
					}
					else    
						dp[i][j][o] += dp[i-1][j][o];
				}
			}
		}
		double answer = 0;
		for(i=1;i<=n;i++)
			for(j=0;j<c;j++)
				answer += j*dp[k][i][j];
		printf("%lf\n", answer);
	}
	return 0;
}

