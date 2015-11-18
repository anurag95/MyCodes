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
int dp[2502][2502];
int data[3][2] = {{3, 2}, {-5, -10}, {-20, 5}};
int find(int h, int a)
{
	if(h<=0 || a<=0)
		return -1;
	else if(dp[h][a]!=-1)
		return dp[h][a];
	else {
		dp[h][a] = 2+max(find(h-2, a-8), find(h-17, a+7));
		return dp[h][a];
	}
}
int main()
{
	for(int i=0;i<2500;i++)
		for(int j=0;j<2500;j++)
			dp[i][j] = -1;
	int t, h, a;
	si(t)
	while(t--)
	{
		scanf("%d%d", &h, &a);
		printf("%d\n", find(h, a));
	}
	return 0;
}

