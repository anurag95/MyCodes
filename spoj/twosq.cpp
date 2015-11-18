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
	ll a, d, i, x, y;
	si(t)
	while(t--)
	{
		scanf("%lld", &a);
		d = sqrt(a);
		int flag=0;
		for(i=1;i<=d;i++)
		{
			x = a-(i*i);
			y=sqrt(x);
			if((y*y)==x)
			{
				flag=1;
				printf("Yes\n");
				break;
			}
		}
		if(!flag)
			printf("No\n");
	}
	return 0;
}

