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
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		double ans = (a * b * c) / (a*b + b*c + c*a + 2*sqrt(a*b*c*(a+b+c)));
		printf("%lf\n", ans);
	}
	return 0;
}

