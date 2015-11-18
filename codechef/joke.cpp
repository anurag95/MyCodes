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
	ll t, n, i;
	sll(t)
	while(t--)
	{
		ll var, x=0;
		scanf("%lld", &n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld", &var);
			scanf("%lld", &var);
			x = x^i;
		}
		printf("%lld\n", x);
	}
	return 0;
}

