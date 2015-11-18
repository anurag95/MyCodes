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
	int t, x, y, var, i;
	pair<int, char> p[2002];
	si(t)
	while(t--)
	{
		sii(x, y);
		int m=0;
		for(i=0;i<x-1;i++){
			si(var);
			p[m++] = make_pair(var, 'x');
		}
		for(i=0;i<y-1;i++){
			si(var);
			p[m++] = make_pair(var, 'y');
		}
		sort(p, p+m);
		int sum = 0, costx=1, costy=1;
		for(i=m-1;i>=0;i--)
		{
			if(p[i].second == 'x'){
				sum += (p[i].first*costy);
				costx++;
			}
			else {
				sum += (p[i].first*costx);
				costy++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

