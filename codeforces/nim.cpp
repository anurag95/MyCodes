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
	ll n, x, m, i, ans = 0;
	sll(n)
	for(i=0;i<n;i++)
	{
		ll temp = 0LL, temp2 = 0LL;
		scanf("%lld%lld", &x, &m);
		if((x+m-1)%4 == 0)
			temp = x+m-1;
		else if((x+m-1)%4 == 1)
			temp = 1;
		else if((x+m-1)%4 == 2)
			temp = x+m;
		else if((x+m-1)%4 == 3)
			temp = 0;
		if((x-1)%4 == 0)
			temp2 = x-1;
		else if((x-1)%4 == 1)
			temp2 = 1;
		else if((x-1)%4 == 2)
			temp2 = x;
		else if((x-1)%4 == 3)
			temp2 = 0;
		ans = ans^temp^temp2;
	}
	if(ans == 0)
		printf("bolik\n");
	else printf("tolik\n");
	return 0;
}

