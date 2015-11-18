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
ll power(ll n)
{
	ll count = 0;
	while(n)
	{
		count++;
		n/=10;
	}
	return count;
}
int main()
{
	int t;
	ll n;
	si(t)
	while(t--)
	{
		scanf("%lld", &n);
		if(!n)
		{
			printf("0\n");
			continue;
		}
		ll max = INT_MIN;
		ll temp = n;
		ll dig = power(n);
		dig--;
		ll copy = dig;
		if(dig == 0)
		{
			printf("%lld\n", n);
			continue;
		}
		while(dig--)
		{
			temp = temp/10 + (temp%10)*pow(10, copy);
			if(max<temp)
				max = temp;
			copy = power(temp)-1;
//			printf("%lld\n", temp);
		}
		dig = power(n);
		temp = n;
		dig--;
		copy = dig;
//		printf("Copy %lld\n", copy);
		while(dig--)
		{
			temp = (temp%((ll)pow(10, copy)))*10 + temp/(ll)(pow(10, copy));
			if(max < temp)
				max = temp;
			copy = power(temp)-1;
	//		printf("%lld\n", temp);
		}
		printf("%lld\n", max);
	}
	return 0;
}

