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
	double x, k;
	while(t--)
	{
		scanf("%lf%lf", &x, &k);
		double it = 1, y = x;
		while(it <= k)
		{
			it*=2;
			y/=2;
		}
		it/=2;
		y*=2;
		printf("%lf\n", (k-it)*y + y/2);
	}
	return 0;
}

