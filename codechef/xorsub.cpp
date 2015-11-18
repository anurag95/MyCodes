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
	int xo, i, t, var, n, k, arr[1005]; 
	si(t)
	while(t--)
	{
		scanf("%d%d", &n, &k);
		for(i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n);
		int bit = 1<<20;
		i = n-1;
		int max = k;
		while(bit && i>=0)
		{
			var = k;
			if(bit&arr[i])
			{
				int x = var^arr[i];
		//		printf("x: %d\n", x);
				if(x > max)
					max = x;
				i--;
			}
			else {
				if(k < max)
					k = max;
				max = k;
				//printf("%d\n", bit);
				bit>>=1;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}

