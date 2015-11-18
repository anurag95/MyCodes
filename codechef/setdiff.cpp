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
ll mypow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}
int main()
{
	int t, n, arr[100010];
	si(t)
	while(t--)
	{
		int i;
		si(n)
		for(i=0;i<n;i++)
		{
			si(arr[i]);
		}
		ll two = 1, ans = 0LL, temp;
		sort(arr, arr+n);
		for(i=0;i<n;i++)
		{
			temp = mypow(2, i);
			ans = (ans + ((arr[i])*temp)%mod)%mod;
		}
		for(i=0;i<n;i++)
		{
			temp = mypow(2, n-i-1);
			ans = (ans + mod - ((arr[i])*temp)%mod)%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

