#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld", x);
int main()
{
	int t;
	si(t)
	while(t--)
	{
		ll num, start = 0, two=2;
		int dig = 0;
		sll(num)
		while(start<num)
		{
			start = start + two;
			two*=2;
			dig++;
		}
		start -= (two/2);
		ll ten = 1, ans = num-start-1, fin=0;
		int i=0;

		while(i<dig)
		{
			if(ans&1)
				fin += 6*ten;
			else fin += 5*ten;
			ten*=10;
			ans>>=1;
			i++;
		}
		pll(fin)
		if(t>0)
			printf("\n");
	}
	return 0;
}

