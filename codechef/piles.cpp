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
	int t, var, n, arr[100010], i;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		int maxi = INT_MIN;
		memset(arr, 0, sizeof(arr));
		for(int i=0;i<n;i++)
		{
			scanf("%d", &var);
			arr[var]++;
			maxi = max(maxi, arr[var]);
		}
		printf("%d\n", n-maxi);
	}
	return 0;
}

