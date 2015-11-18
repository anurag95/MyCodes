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
	int t, n, arr[1000010];
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &arr[i]);
		}
		int flag=0;
		if(next_permutation(arr, arr+n))
		{
			for(int i=0;i<n;i++)
				printf("%d", arr[i]);
			printf("\n");
		}
		else 
			printf("-1\n");
	}
	return 0;
}

