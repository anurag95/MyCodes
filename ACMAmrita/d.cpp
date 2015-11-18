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
	int n, q, query;
	int arr[100010];
	ll sum[100010];
	si(n);
	for(int i=0;i<n;i++)
		si(arr[i]);
	sort(arr, arr+n);
	sum[0] = (ll)arr[0];
	for(int i=1;i<n;i++)
		sum[i] = sum[i-1] + (ll)arr[i];
	si(q);
	while(q--)
	{
		si(query);
		int need = ceil(n/(query+1));
		ll ans = sum[need];
		printf("%lld\n", ans);
	}
	return 0;
}

