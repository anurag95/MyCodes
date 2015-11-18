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
	ll t, n, arr[100010], pre[100010], suf[100010];
	sll(t)
	while(t--)
	{
		sll(n)
		for(int i=0;i<n;i++)
			sll(arr[i]);
		pre[0] = arr[0];
		for(int i=1;i<n;i++)
			pre[i] = pre[i-1]+arr[i];
		suf[n-1] = arr[n-1];
		for(int i=n-2;i>=0;i--)
			suf[i] = suf[i+1]+arr[i];
		ll max = INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(i == 0)
			{
				max = min(max, suf[1]);
			}
			else if(i == n-1)
			{
				max = min(max, pre[n-2]);
			}
			else max = min(max, min(2*pre[i-1]+suf[i+1], 2*suf[i+1]+pre[i-1]));
		}
		printf("%lld\n", max);
	}
	return 0;
}

