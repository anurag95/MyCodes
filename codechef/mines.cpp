#include<stdio.h>
#define mod 1000000007
#define ll long long 
using namespace std;
int main()
{
	ll t, n, m;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &m);
		ll ans = m, i;
		for(i=1;i<n;i++)
		{
			if(i&1)
				ans = ((ans*2)%mod-2+mod)%mod;
			else    ans = ((ans*3)%mod-2+mod)%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
