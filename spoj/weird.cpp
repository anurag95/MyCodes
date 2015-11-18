#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
int main()
{
	int t;
	ll a, b, c, n;
	ll ans=1, var;
	scanf("%d", &t);
	while(t--)
	{
		priority_queue<ll, vector<ll>, less<ll> > low;
		priority_queue <ll, vector<ll>, greater<ll> > high;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		low.push(1);
		ll tmp;
		ans = 1;
		for(int i=2;i<=n;i++)
		{
			tmp = low.top();
			var = a*tmp + b*i + c;
			if(var >= mod) var%=mod;
			ans+=var;
			if(!(i&1))
			{
				if(var < tmp) {
					high.push(tmp);
					low.pop();
					low.push(var);
				}
				else high.push(var);
			}
			else {
				tmp = high.top();
				if(var>tmp){
					high.pop();
					low.push(tmp);
					high.push(var);
				}
				else low.push(var);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

