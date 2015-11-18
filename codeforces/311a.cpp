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
	int n, a, b, c, d, e, f, x, y, z;
	si(n)
		sii(a, b);
		sii(c, d);
		sii(e, f);
		x = min(b, n - c - e);
		y = min(n-x-e, d);
		z = min(n-x-y, f);
		printf("%d %d %d\n", x, y, z);
	return 0;
}

