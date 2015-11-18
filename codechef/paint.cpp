#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000009
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
int main()
{
	int t;
	si(t)
	int m, n, i;
	while(t--)
	{
		scanf("%d%d", &n, &m);
		ll ans = 1;
		pair<int, char> p[100010];
		for(i=0;i<m;i++)
		{
			getchar();
			scanf("%c%d", &p[i].second, &p[i].first);
		}
		sort(p, p+m);
		for(i=1;i<m;i++)
		{
			if(p[i].second != p[i-1].second)
				ans = (ans*(p[i].first - p[i-1].first))%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

