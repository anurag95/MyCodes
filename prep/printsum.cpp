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
	int n;
	int a, b, c, d, co=0;
	si(n)
	for(a=1;a<=(n/4);a++)
		for(b=a;b<=(n-a)/3;b++)
			for(c=b;c<=(n-a-b)/2;c++)
			{
				d = n-a-b-c;
				if(d >= c)
					co++;
			}
	pi(co);
	return 0;
}

