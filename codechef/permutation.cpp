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
ll find(ll n)
{
	return (n*(n+1))/2;
}
int main()
{
	int t;
	ll n, arr[100010], k, i;
	si(t)
	while(t--)
	{
		scanf("%lld%lld", &n, &k);
		for(i=0;i<k;i++)
			scanf("%lld", &arr[i]);
		sort(arr, arr+k);
		ll sum=0, r, l = 0;
		for(i=0;i<k;i++)
		{
			r = arr[i];
			sum += (find(r-1) - find(l));
			if(sum < r)
				break;
			l = r;
		}
		if(k == 0)
			r = (n*(n+1))/2 + 1;
		else if(i == k){
			sum += find(n) - find(r);
			r = sum+1;
		}
		if(r%2 == 0)
			printf("Mom\n");
		else printf("Chef\n");
	}
	return 0;
}

