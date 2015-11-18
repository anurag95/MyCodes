#include <stdio.h>
#define ll long long int
int mod=1000000007,n;
int a[100];
int dp[100][100];
ll solve(int start,int end)
{
	int count=1;int i,j; 
	if(end<=start)return count;
	if(dp[start][end]!=-1)return dp[start][end];
	for(i=start;i<end;i++)
	{	if(a[i]>0)continue;
		for(j=i+1;j<=end;j++)
		{
			if(a[j]==(-a[i]))
			{	
				count=((count%mod)+((solve(i+1,j-1)*1LL*solve(j+1,end))%mod))%mod;
			}
		}
	}
	return dp[start][end]=count;
}
int main(void) {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)for(j=0;j<n;j++)dp[i][j]=-1;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	printf("%d\n",solve(0,n-1));
	return 0;
}

