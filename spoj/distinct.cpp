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
	ll ans;
	ll t, i, last[130], sum[100010];
	char str[100010];
	sll(t)
	while(t--)
	{
		//sum = sm+2;
		for(i=0;i<120;i++)
			last[i] = -1;
		sum[0] = 1;
		scanf("%s", str);
		ll n = strlen(str);
		for(i=0;i<n;i++)
		{
			sum[i+1] = (sum[i]*2)%mod;
			if(last[str[i]]!=-1)
				sum[i+1] = (sum[i+1]-sum[last[str[i]]-1]+mod)%mod;
			last[str[i]] = i+1;
		}
		printf("%lld\n", sum[n]);
	}
	return 0;
}

