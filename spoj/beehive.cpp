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
	si(n)
	while(n!=-1)
	{
		n--;
		int i=1;
		while(n>0)
		{
			n-=(6*i);
			i++;
		}
		if(!n)
			printf("Y\n");
		else 
			printf("N\n");
		si(n)
	}
	return 0;
}

