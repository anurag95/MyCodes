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
	int t, n, i, arr[100010];
	ll sum, cur;
	si(t)
	while(t--)
	{
		sum = cur = 0LL;
		si(n);
		for(i=0;i<n;i++)
			si(arr[i])
		for(i=0;i<n;i++)
		{
			if(arr[i]>cur){
				sum += (ll)(arr[i]-cur);
			}
			cur = (ll)arr[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}

