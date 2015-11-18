#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t, a, b, sum;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld%lld%lld", &a, &b, &sum);
		ll n = (sum*2)/(a+b);
		ll d = (b-a)/(n-5);
		ll first = a-2*d; 
		printf("%lld\n%lld", n, first);
		for(int i=1;i<n;i++)
			printf(" %lld", first+i*d);
		printf("\n");
	}
	return 0;
}
