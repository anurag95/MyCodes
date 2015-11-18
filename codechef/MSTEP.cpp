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
	int i, j, t, n, var;
	pair<int, int> p[250001];
	int arr[501][501];
	si(t)
	while(t--)
	{
		si(n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d", &var);
				p[var] = make_pair(i+1, j+1);
			}
		}
		int count=0;
		for(i=2;i<=n*n;i++){
			int a = abs(p[i].first-p[i-1].first) + abs(p[i].second-p[i-1].second);
//			printf("%d\n", a);
			count += a;
		}
		printf("%d\n", count);
	}
	return 0;
}

