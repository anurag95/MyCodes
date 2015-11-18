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
	int t, n, arr[100010], var;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0;i<100001;i++)
			arr[i] = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &var);
			arr[var]++;
		}
		int count=0;
		for(int i=0;i<100001;i++)
		{
			if(arr[i] != 0)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}

