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
	int t, n, arr[501], m, d;
	si(t)
	while(t--)
	{
		scanf("%d%d%d", &n, &m, &d);
		int i, var, count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &var);
			var--;
			count+= (var/d);
		}
		if(count >= m)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

