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
	int t;
	ll s, c, k;
	si(t)
	while(t--)
	{
		scanf("%lld%lld%lld", &s, &c, &k);
		ll count = 0;
		if((s-k) >= 0)
		{
			count += (1LL)<<(s-k+1);
			count += 1;
		}
		if(k == 1)
		{
			ll var = c;
			while(var >= s && (var)){
				count += (1LL)<<var;
				var--;
			}
		}
//		else if(c > abs(s-k+1))
//			count += (1LL)<<(s-k+1);
		if(k>1 && (s-k) > (-1))
		{
			if(c && c>(s-k))
				count += (1LL)<<(s-k+1);
		}
		printf("%lld\n", count);
	}
	return 0;
}

