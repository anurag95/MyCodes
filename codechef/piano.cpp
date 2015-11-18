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
	char str[102];
	int n, sum;
	si(t)
	while(t--)
	{	
		scanf("%s", str);
		si(n);
		sum = 0;
		ll count = 0LL;
		for(int i=0;str[i];i++)
			sum += (str[i] == 'S'?1:2);
		n*=12;
		for(int i=1;i<=n;i++)
		{
			int j = i;
			while(j+sum <= n)
			{
				count += (ll)(1);
				j+=sum;
			}
		}
		printf("%lld\n", count);
	}
	return 0;
}

