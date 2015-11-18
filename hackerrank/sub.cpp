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
ll C(ll n)
{
	return (n*(n-1))/2;
}
int main()
{
	ll i, n, k;
	ll var, sum[102]={0};
	cin>>n>>k;
		ll ans=0;
		ll s=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld", &var);
			s+= var;
			sum[s%k]++;
		}
		sum[0]++;
		for(i=0;i<k;i++)
		{
			if(sum[i] > 1)
				ans += C(sum[i]);
		}
		printf("%lld\n", ans);
	return 0;
}
