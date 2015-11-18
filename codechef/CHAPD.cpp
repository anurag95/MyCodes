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

ll hcf(ll a, ll b)
{
	ll r;
	while(b){
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t;
	ll i, a, b;
	si(t)
	while(t--)
	{	
		sll(a);
		sll(b);	
		ll c, h = hcf(a, b);
		b/=h;
		while(b!=1){
			c = hcf(h, b);
			if(c == 1)
				break;
			else b/=c;
		}
		if(b == 1)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

