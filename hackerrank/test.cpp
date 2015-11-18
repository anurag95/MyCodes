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
ll dp[33][33], n;
char arr[33][33];
ll find(ll i, ll j)
{
	if(i==n || j==n)
		return 0;
	if(i==n-1 && j==n-1)
		return dp[i][j] = 1;
	if(arr[i][j] == '#')
		return dp[i][j] = 0;
	else if(dp[i][j] != -1)
		return dp[i][j];
	else {
		dp[i][j] = find(i, j+1) + find(i+1, j);
		return dp[i][j];
	}
}
int main()
{
	ll t, j, i;
	sll(t)
	while(t--)
	{
		ll min=INT_MAX;
		scanf("%lld", &n);
//		for(i=0;i<n;i++)
//			for(j=0;j<n;j++)
//				dp[i][j] = -1;
		for(i=0;i<n;i++)
			scanf("%s", arr[i]);
//		printf("ans %d\n", find(0, 0));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(arr[i][j]!='#')
				{
					if(i==0&&j==0)
						continue;
					if(i==(n-1)&&j==(n-1))
						continue;
					//memset(dp, -1, sizeof(dp));
					for(ll k=0;k<n;k++)
						for(ll l=0;l<n;l++)
							dp[k][l] = -1;
					arr[i][j] = '#';
					ll a=find(0, 0);
					if(min>a)
						min=a;
					arr[i][j] = '.';
				}
			}
		}
		printf("%lld\n", min);
	}
	return 0;
}


