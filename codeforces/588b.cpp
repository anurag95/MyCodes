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
int arr[1000002];
vector<int> sieve;
int main()
{
	for(int i=0;i<1000002;i++)
		arr[i] = 1;
	arr[0] = arr[1] = 0;
	for(int i=2;i<1000002;i++)
	{
		if(arr[i] == 1){
			for(ll j=(ll)i*i;j<(ll)1000002;j+=(ll)i)
				arr[j] = 0;
		}
	}
	for(int i=0;i<1000002;i++)
		if(arr[i] == 1)
			sieve.pb(i);
	ll n;
	sll(n)
	ll d = (ll)sqrt(n);
//	for(int i=sieve.size()-5;i<sieve.size();i++)
//		pi(sieve[i]);
	
	int i=0;
	ll ans = 1LL;
	while(i<sieve.size() && sieve[i] <= d){
		if(n%sieve[i] == 0)
			ans = ans*(ll)sieve[i];
		while(n%sieve[i] == 0)
			n/=sieve[i];
		i++;
	}
	ans = ans*(ll)n;
	printf("%lld\n", ans);
	return 0;
}

