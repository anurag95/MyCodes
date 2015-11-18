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
	int b, t;
	si(t)
	while(t--)
	{
		si(b);
		b = (b-2)/2;
		if(b<=0)
			printf("0\n");
		else printf("%d\n", b*(b+1)/2);
	}
	return 0;
}

