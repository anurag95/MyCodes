/*
   n-1 C r-1
*/

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
	si(t)
	while(t--)
	{
		ll ans=1, n, i, r;
		scanf("%lld%lld", &n, &r);
		n--;
		r--;
		if(r > n-r)
			r = n-r;
		for(i=1;i<=r;i++)
		{
			ans = ans*(n-i+1);
			ans = ans/(i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

