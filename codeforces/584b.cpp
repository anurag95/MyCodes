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
	int n, i;
	si(n)
	ll arr[100001], arr2[100001];
	arr2[0] = 1;
	for(i=1;i<=n;i++)
		arr2[i] = (arr2[i-1]*7)%mod;
	arr[0] = 1;
	arr[1] = 20;
	for(i=2;i<=n;i++)
	{
		arr[i] = ((((ll)27*arr[i-1])%mod) + (((ll)20*arr2[i-1])%mod))%mod; 
	}
	printf("%lld\n", arr[n]);
	return 0;
}

