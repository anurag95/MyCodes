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
	ll t;
	ll n, i, k;
	ll var;
	sll(t)
	while(t--)
	{
		ll ans=1LL;
		ll breadleft;
		scanf("%lld%lld", &n, &k);
		breadleft = k;
		for(i=0;i<n;i++)
		{
			scanf("%lld", &var);
			if(var <= breadleft){
				breadleft -= (var+1);
				if(breadleft <= 0){
					ans++;
					breadleft = k;
				}
			}
			else if(var > breadleft){
				var -= breadleft;
				ans++;
				breadleft = k;
				
				if(var > k){
					ans = ans + (var/k);
					var = (var%k);
				} 
		
				if(var <= breadleft && var>0){
					breadleft -= (var+1);
					if(breadleft <= 0){
						ans++;
						breadleft = k;
					}
				}
			}
		}
		if(breadleft == k)
			ans--;
		printf("%lld\n", ans);
	}
	return 0;
}

