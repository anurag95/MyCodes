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
	ll i, n, p, var, x, maxi = 0, ind = 0;
	sll(n);
	sll(p);
	sll(x);
	for(i=0;i<n;i++)
	{
		sll(var);
		if(var*p > maxi){
			ind = i+1;
			maxi = var*p;
		}
		p-=x;
	}
	printf("%lld\n", ind);
	return 0;
}

