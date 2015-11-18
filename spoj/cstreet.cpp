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
vector<pair<int,int> > vec[1001];
int main()
{
	int t, i, j, p, n, m, u, v, len;
	si(t)
	while(t--)
	{
		scanf("%d%d%d", &p, &n, &m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d", &u, &v, &len);
			vec[u].pb(make_pair(v, len));
			vec[v].pb(make_pair(u, len));
		}
		priority_queue<>
	}
	return 0;
}

