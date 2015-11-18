#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll arr[1005][1005];
int main()
{
	ll n, i, j, t;
	scanf("%lld", &t);
	for(i=1;i<=1000;i++)
	{
		arr[i][0] = 0;
		arr[1][i] = 0;
		arr[0][i] = 0;
	}
	arr[1][1] = 1;
	arr[0][0] = 0;
	for(i=2;i<=1000;i++)
	{
		for(j=1;j<=i;j++)
		{
			arr[i][j] = ((j*arr[i-1][j])%mod + arr[i-1][j-1])%mod;
		}
	}
	ll ans[1005], sum=0;
	for(i=0;i<=1000;i++)
	{
		sum=0;
		for(j=0;j<=i;j++)
		{
			sum = (sum+arr[i][j])%mod;
		}
		ans[i] = sum;
	}
	while(t--)
	{
		scanf("%lld", &n);
		printf("%lld\n", ans[n]);	
	}
	return 0;
}

