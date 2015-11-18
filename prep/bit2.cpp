// functions for range update and range query

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
ll size;
ll bit[100010], bit2[100010];
void update(ll bt[], ll idx, ll val) // increase the value at idx by val
{
	for(; idx<= size; idx += (idx&(-idx)))
		bt[idx] += (ll)val;
}
ll q(ll bit[], ll idx) // return sum from [1..b]
{
	ll sum = 0;
	for(;idx>0;idx-=(idx&(-idx)))
		sum += bit[idx];
	return sum;
}
ll query(ll n)
{
	return q(bit, n)*n - q(bit2, n);
}
ll rangequery(ll a, ll b) // return sum from [a..b]
{
	return query(b) - query(a-1);
}

void rangeupdate(ll l, ll r, ll val)  // update values over a range
{
	update(bit, l, val);
	update(bit, r+1, -val);
	update(bit2, l, val*(l-1));
	update(bit2, r+1, -val*r);
}

int main()
{
	ll t;
	scanf("%lld", &t);
	while(t--)
	{
		memset(bit, 0, sizeof(bit));
		memset(bit2, 0, sizeof(bit2));
		scanf("%lld", &size);
		ll var;
		ll q, type, x, y;
		sll(q)
			while(q--)
			{
				scanf("%lld%lld%lld", &type, &x, &y);
				if(type == 0)
				{
					scanf("%lld", &var);
					rangeupdate(x, y, var);
				}
				else {
					printf("%lld\n", rangequery(x, y));
					//			printf("%d\n", rangequery(x, y));
			}
//				for(int i=0;i<size;i++)
//				{
//					printf("%d ", bit[i+1]);
//				}
//				printf("\n");
			}
	}
	return 0;
}

