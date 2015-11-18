#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lf", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
int main()
{
	int t;
	double d1, d2, d;
	si(t)
	while(t--)
	{
		sll(d1)
		sll(d2)
		sll(d)
		if(d2 > d+d1)
			printf("%lf\n", d2-d-d1);
		else if(d1 > d+d2)
			printf("%lf\n", d1-d-d2);
		else if(d-d1-d2<0)
			printf("0\n");
		else printf("%.6lf\n", d-d1-d2);
	}
	return 0;
}

