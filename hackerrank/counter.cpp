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
	unsigned long long int a;
	int t;
	si(t)
	while(t--)
	{
		scanf("%llu", &a);
		int turn=0;
		while((a&1)==0)
		{
			turn++;
			a>>=1;
		}
		while(a)
		{
			if(a&1)
				turn++;
			a>>=1;
		}
		if(turn%2)
			printf("Richard\n");
		else printf("Louise\n");
	}
	return 0;
}

