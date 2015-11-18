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
void multi(ll a[][2], ll b[][2])
{
	ll c[][2] = {{0, 0}, {0, 0}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
				c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
		}
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			a[i][j] = c[i][j];
}
ll calc(ll n)
{
	ll res[2][2] = {{1, 0}, {0, 1}}, base[2][2] = {{1, 1}, {1, 0}};
	while(n)
	{
		if(n&1)
			multi(res, base);
		n>>=1;
		multi(base, base);
	}
	return res[0][0];
}
int main()
{
	int t;
	ll n;
	si(t)
	while(t--)
	{
		sll(n);
		printf("$%lld\n", (calc(n)*calc(n+1)+mod-1)%mod);
	}
	return 0;
}

