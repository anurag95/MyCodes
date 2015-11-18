#include <cstdio>
#define max(a,b) (a)>(b)?(a):(b)

typedef long long ll;

int n,arr[10004];

ll dp[10004];
ll func(int pos)
{
	if(pos>=n)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	return dp[pos]=max(arr[pos]+func(pos+2),func(pos+1));
}

int main()
{
	int t,ctr=1,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			dp[i]=-1;
		}
		printf("Case %d: %lld\n",ctr++,func(0));
	}
	return 0;
}
