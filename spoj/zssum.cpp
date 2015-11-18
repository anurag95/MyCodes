#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 10000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
ll mypow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1)
			res = (res*a)%mod;
		b>>=1;
		a = (a*a)%mod;
	}
	return res;
}
int main()
{
	ll n, k;
	scanf("%lld%lld", &n, &k);
	while(n || k)
	{
		ll a = mypow(n-1, k);
		ll b = mypow(n, k);
		a = (a*2)%mod;
		ll c = mypow(n, n);
		ll d = mypow(n-1, n-1);
		d = (d*2)%mod;
		d = (a+b+c+d)%mod;
		pll(d)
		scanf("%lld%lld", &n, &k);
	}
	return 0;
}

