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
	si(t)
	while(t--)
	{
		int n, var = 10, flag=0;
		scanf("%d", &n);
		if(n==1 || n==10 || n==100 || n==1000 || n==10000 || n==100000 || n==1000000 )
		{
			printf("NO\n");
			continue;
		}
		else {
			printf("YES\n");
			continue;
		}	
	}
	return 0;
}

