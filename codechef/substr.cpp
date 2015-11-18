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
ll prefix[100010], arr[100010], zero[100010], one[100010], logs[100010];
int main()
{
	int t;
	ll *a, *b;
	ll ans, i;
	ll n, k, q, l, r;
	ptrdiff_t x, y;
	si(t)
	char c;
	while(t--)
	{
		sll(n)
		sll(k)
		sll(q)
		getchar();
		zero[0] = one[0] = prefix[0] = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%c", &c);
			arr[i] = (int)(c-48);
			if(arr[i])
			{
				zero[i] = zero[i-1];
				one[i] = one[i-1]+1;
			}
			else 
			{
				zero[i] = zero[i-1]+1;
				one[i] = one[i-1];
			}
		}

		for(i=1;i<=n;i++)
		{
			a = upper_bound(zero+i, zero+n+1, zero[i-1]+k);
			b = upper_bound(one+i, one+n+1, one[i-1]+k);
			x = a-zero;
			y = b-one;
			if(x>y)
				logs[i] = ((long int)y-1);
			else logs[i] = ((long int)x-1);
			prefix[i] = prefix[i-1]+logs[i]-i+1;
		}	
		while(q--)
		{
			sll(l)
			sll(r)
			ans = 0;
			a = upper_bound(logs+l, logs+r+1, r);
			x = (long int)(a-logs);
			ans += prefix[x-1] - prefix[l-1];
			ans += (r-x+1)*(r-x+2)/2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}

