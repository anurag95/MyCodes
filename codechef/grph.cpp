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
ll n, m, k, i, j, row, col;

struct ele {
	ll n;
	ll m;
	int start; // 0 if end node, else 1
	ll val; //ways of reaching there
};

ll power(ll a, ll b)
{
	if(b <= 0)
		return 1;
	ll res = 1;
	while(b)
	{
		if(b&1)
			res = (res*(a%mod))%mod;
		b>>=1;
		a = (a*a)%mod;
	}
	return res%mod;
}

map< pair<ll, ll>, ll> values;

ll array[100010] = {0}; // to connect the start and end edges after sorting

bool cmp(ele a, ele b)
{
	if(a.n != b.n)
		return (a.n < b.n);
	if(a.start == 0)
		return false;
	if(b.start == 0)
		return false;
	if(a.m != b.m)
		return (a.m < b.m);
	return false;
}

int main()
{
	ele s[100010];
	scanf("%lld%lld%lld", &n, &m, &k);
	for(j=0,i=0;i<k;i++)
	{
		scanf("%lld%lld", &row, &col);
		s[j].n = row;
		s[j].m = col;
		s[j].val = i;
		s[j++].start = 1;
		scanf("%lld%lld", &row, &col);
		s[j].n = row;
		s[j].m = col;
		s[j].val = i;
		s[j++].start = 0;
	}
	sort(s, s+2*k, cmp);
	for(i=0;i<2*k;i++)
	{
		if(s[i].start == 1)
			array[s[i].val] = i;
		else s[i].val = array[s[i].val];
	}
	for(i=0;i<2*k;i++)
		printf("%lld %lld %lld %d\n", s[i].n, s[i].m, s[i].val, s[i].start);
	ll ans = 1;
	ans = power(m, s[0].n - 1);
	s[0].val = ans;
	if(s[0].n != 0) //if its not starting at the very start, multi by m for that level
		ans = (ans*m)%mod;
//	values[make_pair(s[0].n, s[0].m)] = ans;
	for(i=1;i<2*k;i++)
	{
		if(s[i].start == 0) // ending node
		{
			ans	= (ans*power(m, s[i].n - s[i-1].n - 1))%mod;
			values[make_pair(s[i].n, s[i].m)] += (ans+s[s[i].val].val);
			if((s[i].n != (n+1))) // ending at the very last
				ans = (ans*m)%mod;
			ans = (ans+s[s[i].val].val)%mod;
		}
		else if(s[i].start == 1) //starting node
		{
			ans = (ans*power(m, s[i].n-s[i-1].n - 1))%mod;
			if((s[i].start != s[i-1].start) && (s[i].n == s[i-1].n)) // starting and ending coincide
				s[i].val = values[make_pair(s[i].n, s[i].m)];
			else if((s[i].start == s[i-1].start)&&(s[i].n==s[i-1].n)) //starting and starting coincide
			{
				s[i].val = ans/m;
			}
			else { 
				s[i].val = ans;
				if(s[i].n != 0)
					ans = (ans*m)%mod;
			}
		}
	}
	ans = (ans*power(m, n-s[i-1].n))%mod;
	printf("%lld\n", ans);
	return 0;
}

