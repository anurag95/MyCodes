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
	int t, arr[100010];
	si(t)
	while(t--)
	{
		int n;
		si(n)
		for(int i=0;i<n;i++)
			si(arr[i])
		sort(arr, arr+n);
		int sum=0;
		for(int i=n-1;i>=0;i-=2)
			sum += arr[i];
		pi(sum);
	}
	return 0;
}

