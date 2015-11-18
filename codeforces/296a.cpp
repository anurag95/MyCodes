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
	ll a, b;
	sll(a)
	sll(b)
	ll count = 0;
	while(a!=b){
		count += a/b;
		a -= b*(a/b);
		if(a == 0)
			break;
		if(a<b)
		{
			ll c = a;
			a = b;
			b = c;
		}
	}
	if(a!=0)
	count += 1;
	printf("%lld\n", count);
	return 0;
}

