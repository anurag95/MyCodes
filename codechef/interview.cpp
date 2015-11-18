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
int main()
{
	int t, n;
	ll ans;
	si(t)
	while(t--)
	{
		ans = 0;
		scanf("%d", &n);
		ans += (ll)(1+n);
		int d = sqrt(n);
		for(int i=2;i<=d;i++)
		{
			if(n%i == 0)
				ans += (ll)(i + n/i);
		}
		if(d*d == n && (n%d==0))
			ans -= (ll)(d);
		printf("%lld\n", ans);
	}
	return 0;
}

