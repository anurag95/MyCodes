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
	int t;
	si(t)
	while(t--)
	{
		int var=0, maxi = INT_MIN, m, n, i, arr[110];
		sii(n, m)
		for(i=0;i<n;i++)
		{
			si(arr[i])
			if(arr[i]>maxi)
				maxi = arr[i];
		}
		for(i=0;i<n;i++)
		{
			var += (maxi - arr[i]);
		}
		if(m>=var && (m - var)%n == 0)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

