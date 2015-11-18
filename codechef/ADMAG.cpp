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
	ll n, a, b, c;
	si(t)
	while(t--)
	{	
		sll(n);
		if(n==1 || n==2)
		{
			printf("%lld\n", n);
			continue;
		}
		a=1LL; b=2LL; c=3;
		ll count=1LL;
		while(b<=n){
			a=b; b=c;
			c = a+b;
			count++;
		}
		printf("%lld\n", count);
	}
	return 0;
}

