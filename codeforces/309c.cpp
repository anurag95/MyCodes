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
	int i, j;
	ll pascal[1001][1001] = {0};
	pascal[0][0] = 1;
	for(i=1;i<1000;i++)
	{
		pascal[i][0] = 1;
		for(j=1;j<=i;j++)
			pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1])%mod;
	}
	int k;
	scanf("%d", &k);
	int c[1001];
	for(i=0;i<k;i++)
		scanf("%d", &c[i]);
	int tot=0;
	ll res=1;
	for(i=0;i<k;i++)
	{
		res = (res*pascal[tot+c[i]-1][c[i]-1])%mod;
		tot+=c[i];
	}
	printf("%lld\n", res);
	return 0;
}

