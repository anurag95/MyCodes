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
	int t, n, v, x, y, max;
	pair<int, int> p[100010];
	int arr[100010];
	si(t)
	while(t--)
	{
		int i, j;
		si(n);
		for(i=0;i<n;i++)
		{
			si(v);
			max = INT_MIN;
			for(j=0;j<v;j++)
			{
				sii(x, y);
				if(x>max)
					max = x;
			}
			p[i] = make_pair(max, i);
		}
		sort(p, p+n);
		for(i=0;i<n;i++)
			arr[p[i].second] = i;
		printf("%d", arr[0]);
		for(i=1;i<n;i++)
			printf(" %d", arr[i]);
		printf("\n");
	}
	return 0;
}

