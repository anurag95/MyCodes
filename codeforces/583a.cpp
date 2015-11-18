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
	int n, h, v;
	int ver[52] = {0};
	int hor[52] = {0};
	si(n)
	sii(h, v);
	printf("1");
	ver[v] = hor[h] = 1;
	for(int i=1;i<n*n;i++)
	{
		sii(h, v);
		if(!ver[v] && !hor[h])
		{
			printf(" %d", i+1);
			ver[v] = hor[h] = 1;
		}
	}
	printf("\n");
	return 0;
}

