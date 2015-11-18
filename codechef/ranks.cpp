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
	ll t, n, s;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &s);
		ll sum=0, i=1;

		s-=n;
		n--;
		while((sum+i)<=s)
		{
			sum+=i;
			i++;
			n--;
		}
//		if(sum==s && n==0)
//			n--;
		printf("%lld\n", n);

	}
	return 0;
}

