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
	int x, y, a, b, p, q;
	sii(x, y);
	sii(a, b);
	sii(p, q);
	int flag = 0;
	if(a+p<=x && b<=y && q<=y)
		printf("YES\n");
	else if(a+p<=y && b<=x && q<=x)
		printf("YES\n");
	else if(a+q<=x && b<=y && p<=y)
		printf("YES\n");
	else if(a+q<=y && b<=x && p<=x)
		printf("YES\n");
	else if(b+q<=x && a<=y && p<=y)
		printf("YES\n");
	else if(b+q<=y && a<=x && p<=x)
		printf("YES\n");
	else if(b+p<=x && a<=y && q<=y)
		printf("YES\n");
	else if(b+p<=y && a<=x && q<=x)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}

