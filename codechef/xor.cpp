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
	int t, i, j, var, ans[1034], xo[1034], n, k;
	si(t)
	while(t--)
	{
		scanf("%d%d", &n, &k);
		for(i=0;i<1034;i++)
		{
			ans[i] = 0;
			xo[i] = 0;
		}
		ans[k] = 1;
		for(i=0;i<n;i++)
		{
			scanf("%d", &var);
			for(j=0;j<1034;j++)
			{
				if(ans[j] == 1)
				{
					int var2 = j^var;
					xo[var2] = 1;
				}
			}
			for(j=0;j<1034;j++)
			{
				if(xo[j] == 1)
					ans[j] = 1;
				xo[j] = 0;
			}
		}
		int max = 0;
		for(i=0;i<1034;i++)
		{
//			printf("%d ", ans[i]);
			if(ans[i] == 1)
				max = i;
		}
		printf("%d\n", max);
	}
	return 0;
}

