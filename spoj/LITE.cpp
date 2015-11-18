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
	int n, m, i, type, a, b;
	sii(n, m);
	for(i=0;i<m;i++)
	{
		si(type)
		sii(a, b)
		if(type == 0)
		{
			rangeupdate(a, b);
		}
		else {
			printf("%d\n", rangequery(a, b));
		}
	}
	return 0;
}

