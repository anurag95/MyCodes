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
	int t, j=1;
	si(t)
	while(t)
	{
		double size, cost;
		double min;
		double ans;
		scanf("%lf%lf", &size, &cost);
		min = (size*size)/cost;
		ans = size;
		for(int i=1;i<t;i++)
		{
			scanf("%lf%lf", &size, &cost);
			if(min < (size*size)/cost)
			{
				min = (size*size)/cost;
				ans = size;
			}
		}
		printf("Menu %d: %.0lf\n", j++, ans);
		si(t)
	}
	return 0;
}

