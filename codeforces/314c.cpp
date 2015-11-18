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
map<int, ll> M, dp;
int main()
{
	ll ans=0;
	int n, k, num, i;
	sii(n, k)
	for(i=0;i<n;i++)
	{
		si(num)
		if(num%k==0 && (num/k)%k==0){
			ans += dp[num/k];
			dp[num] += M[num/k];
		}
		else if(num%k == 0){
			dp[num] += M[num/k];
		}
		else {
			
		}
		M[num]++;
	}
	printf("%lld\n", ans);
	return 0;
}

