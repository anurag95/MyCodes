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
	ll counter=0, t, n, i, arr[1000010];
	sll(t)
	while(t--)
	{
		scanf("%lld", &n);
		for(i=0;i<n;i++)
			scanf("%lld", &arr[i]);
		ll ans=0, sum=0, flag=0;
		for(i=0;i<n;i++)
		{
			sum+=arr[i];
			if(arr[i]<0 && sum<=0)
			{
				flag=1;
				ans += 1+(-sum); 
				sum = 1;
			}
		}
		if(!flag)
			ans+=1;
		counter++;
		printf("Scenario #%lld: %lld\n", counter, ans);
	}
	return 0;
}

