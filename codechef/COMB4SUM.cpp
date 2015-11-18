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
	int i, j, t, n;
	int arr[2005];
	si(t)
	while(t--)
	{
		vector<int> pairsum;
		si(n);

		for(i=0;i<n;i++) 
			si(arr[i])

		sort(arr, arr+n);
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				pairsum.pb(arr[i]+arr[j]);
			}
		}
		
		sort(pairsum.begin(), pairsum.end());
		ll sum = 0;
		int k = pairsum.size();

		for(i=1;i<=k;i++)
		{
			ll num = pairsum[i-1];
			sum = sum + (ll)(i-1)*num - (ll)(k-i)*num;
		}
		sum = sum*(ll)2;
		ll tempsum = 0LL;
		for(i=1;i<=n;i++)
		{
			ll num = arr[i-1];
			tempsum = tempsum + (ll)(i-1)*num - (ll)(n-i)*num;
		}
		tempsum = tempsum*(ll)(2*n-4);
		printf("%lld\n", sum-tempsum);
	}
	return 0;
}

