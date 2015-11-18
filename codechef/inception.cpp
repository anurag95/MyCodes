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
ll n, a[1002], b[1002]; 
ll getmaxarea()
{
	stack<ll> s;
	ll i=0;
	ll ans = 0, temp, top;
	while(i<n)
	{
		if(s.empty() || a[i]>=s.top())
			s.push(i++);
		else {
			top = s.top();
			s.pop();
			temp = a[top]*(s.empty()?i:i-s.top()-1);
			ans = max(ans, temp);
		}
	}
	while(!s.empty())
	{
		top = s.top();
		s.pop();
		temp = a[top]*(s.empty()?i:i-s.top()-1);
		ans = max(ans, temp);
	}
	return ans;
}
int main()
{
	int t;
	ll i;
	si(t)
	while(t--)
	{
		sll(n)
		for(i=0;i<n;i++)
			sll(a[i])
		for(i=0;i<n;i++)
			sll(b[i])
		for(i=0;i<n;i++)
			if(a[i]>b[i])
				a[i] = b[i];
		ll ans = getmaxarea();
		printf("%lld\n", ans);
	}
	return 0;
}

