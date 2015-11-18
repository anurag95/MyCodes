#include<bits/stdc++.h>
#define max 1000000007
using namespace std;
int dp[2050][105];
int rec(int mask, int tid, int n, vector<int> v[])
{
	if(mask == (1<<n)-1)
		return dp[mask][tid] = 1;
	if(tid == 101)
		return 0;
	if(dp[mask][tid] != -1)
		return dp[mask][tid];
	int i, ans = rec(mask, tid+1, n, v);
	for(i=0;i<v[tid].size();i++)
	{
		int j = v[tid][i];
		if(mask&(1<<(j-1)))
			continue;
		ans = (ans%max + rec(mask|(1<<(j-1)), tid+1, n ,v)%max)%max;
	}
	return dp[mask][tid] = ans;
}
int main()
{
	int t, n, i, j, num;
	char var;
	scanf("%d", &t);
	while(t--)
	{
		vector<int> v[102];
		for(i=0;i<2050;i++)
			for(j=0;j<105;j++)
				dp[i][j] = -1;
		scanf("%d", &n);
		getchar();
		for(i=0;i<n;i++)
		{
			var = ' ';
			while(var!='\n')
			{
				scanf("%d", &num);
				v[num].push_back(i+1);
				scanf("%c", &var);
			}
		}
		printf("%d\n", rec(0, 1, n, v));
	}
	return 0;
}
