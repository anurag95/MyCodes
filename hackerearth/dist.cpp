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
	int n;
	int x[200001], y[200001];
	si(n)
	for(int i=0;i<n;i++)
	{
		sii(x[i], y[i]);
	}
	sort(x, x+n);
	sort(y, y+n);
	ll sum = 0;
	for(int i=0;i<n;i++){
		sum = sum + (ll)x[i]*(ll)(2*i-n+1);
		sum = sum%mod;
	}
	for(int i=0;i<n;i++){
		sum = sum + (ll)y[i]*(ll)(2*i-n+1);
		sum = sum%mod;
	}
	printf("%lld\n", sum%mod);

	return 0;
}

