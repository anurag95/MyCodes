#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sl(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pl(x) printf("%lld\n", x);
int main()
{
	int t;
	si(t);
	while(t--)
	{
		ll n;
		sl(n);
		if(n == 1)
			pi(1)
		else if(n&1)
			pl(n/2)
		else {
			if(!((n/2)&1))
				pl(n/2 - 1)
			else {
				pl(n/2 - 2)
			}
		}
	}
	return 0;
}
