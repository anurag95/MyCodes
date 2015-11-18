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

int dp[2050][22], arr[11][21], mini=INT_MAX, n, k;

int rec(int mask, int rid, int setbit, int ans)
{
	if(rid == n)
	{
		return 0;
	}
	if(dp[mask][rid]!=-1)
		return dp[mask][rid];
	int i, ind, myans=INT_MAX, a;
	for(i=0;i<k;i++)
	{
		if(mask&(1<<i) && setbit!=i)
			continue;
		dp[mask|(1<<i)][rid] = rec(mask|(1<<i), rid+1, i, ans+arr[i][rid]);
		if(myans > a)
		{
			myans = a;
			ind = i;
		//myans = min(myans, /* arr[i][rid] + */ rec(mask|(1<<i), rid+1, i, ans+arr[i][rid]));
		//	dp[mask|(1<<k)][rid] = arr[ind][rid] + myans;
		//	ind = i;
		}
	}
	return dp[mask|(1<<ind)][rid] = ans + arr[ind][rid];
}

int main()
{
	int i, j;
	sii(n, k)
	for(i=0;i<k;i++)
		for(j=0;j<n;j++)
			si(arr[i][j])
	for(i=0;i<2050;i++)
		for(j=0;j<22;j++)
			dp[i][j] = -1;
	rec(0, 0, -1, 0);
	int var = (1<<k)-1;
	for(i=0;i<var;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	for(i=0;i<var;i++)
		if(dp[i][n-1]<mini && dp[i][n-1]!=-1)
			mini = dp[i][n-1];
	pi(mini);
	return 0;
}

