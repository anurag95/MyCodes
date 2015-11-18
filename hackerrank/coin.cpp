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
	ll i, t, n;
	sll(t)
	while(t--)
	{
		ll ans = 1;
		scanf("%lld", &n);
		if(n==1)
			printf("0\n");
		else if(n==2)
			printf("2\n");
		else {
			ans = 2;
			for(i=4;i<=(n+1);i++)
			{
				ans = ((ans%mod)*i)%mod;
			}
			ans = (ans*(n-1))%mod;
			printf("%lld\n", ans);
		}
	}
	return 0;
}

