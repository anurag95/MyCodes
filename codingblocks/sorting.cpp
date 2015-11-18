/* 
	Involves sorting the numbers and summing the top three
*/
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
	int t, arr[100010], i, n;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		int sum = arr[n-1]+arr[n-2]+arr[n-3];
		printf("%d\n", sum);
	}
	return 0;
}

