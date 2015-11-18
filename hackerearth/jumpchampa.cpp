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
	int t, n, i, q, arr[1002];
	si(t)
	while(t--)
	{
		sii(n, q);
		for(i=0;i<n;i++)
			si(arr[i])
		sort(arr, arr+n);
		ll ans = 0LL;
		for(i=1;i<n;i++)
		{
			ans = ans + (ll)abs(arr[i] - arr[i-1]);
		}
		ans = (ll)ans*q;
		printf("%lld\n", ans);
	}
	return 0;
}

