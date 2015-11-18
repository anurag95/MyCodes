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
ll dp[1801][301][10];
ll calc(ll r, ll b, ll l)
{
	if(!b)
	{
		if(!r && l>=0)
			return 1;
		return 0;
	}
	if(r<0 || l<0)
		return 0;
	if(dp[r][b][l] != -1)
		return dp[r][b][l];
	ll ans = 0;
	ans = (ans+calc(r, b-1, l))%mod;
	ans = (ans+calc(r-4, b-1, l))%mod;
	ans = (ans+calc(r-6, b-1, l))%mod;
	ans = (ans+calc(r, b-1, l-1))%mod;
	dp[r][b][l] = ans;
	return ans;
}
int main()
{
	int t;
	ll r, b, l;
	memset(dp, -1, sizeof(dp));
	si(t)
	while(t--)
	{
		scanf("%lld%lld%lld", &r, &b, &l);
		if(r%2 || (r>1800))
			printf("0\n");
		else 
			printf("%lld\n", calc(r, b, l));
	}
	return 0;
}

