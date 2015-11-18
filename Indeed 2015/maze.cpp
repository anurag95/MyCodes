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
int dp[102][102], flag[102][102];
char arr[102][102];
int t, mini, r, c, i, j, e1, e2;
int calc(int s1, int s2, int p1, int p2, int turns)
{
	if(s1==e1 && s2==e2)
	{
//		if(mini>turns)
//			mini = turns;
		return 0;
	}
	if(turns>=mini)
		return ;
	if(p1 == -1)
	{
		if(s1+1 <= r && arr[s1+1][s2]!='#' && flag[s1+1][s2]!=1)
		{
			flag[s1+1][s2] = 1;
			calc(s1+1, s2, s1, s2, turns);
			flag[s1+1][s2] = 0;
		}
		if(s1-1 >= 0 && arr[s1-1][s2]!='#' && flag[s1-1][s2]!=1)
		{
			flag[s1-1][s2] = 1;
			calc(s1-1, s2, s1, s2, turns);
			flag[s1-1][s2] = 0;
		}
		if(s2+1 <= c && arr[s1][s2+1]!='#' && flag[s1][s2+1]!=1)
		{
			flag[s1][s2+1] = 1;
			calc(s1, s2+1, s1, s2, turns);
			flag[s1][s2+1] = 0;
		}
		if(s2-1 >= 0 && arr[s1][s2-1]!='#' && flag[s1][s2-1]!=1)
		{
			flag[s1][s2-1] = 1;
			calc(s1, s2-1, s1, s2, turns);
			flag[s1][s2-1] = 0;
		}
		return ;
	}
	else {
		if(s1+1 <= r && arr[s1+1][s2]!='#' && flag[s1+1][s2]!=1)
		{
			flag[s1+1][s2] = 1;
			if(p2==s2-1 || p2==s2+1)
				calc(s1+1, s2, s1, s2, turns+1);
			else 
				calc(s1+1, s2, s1, s2, turns);
			flag[s1+1][s2] = 0;
		}
		if(s1-1 >= 0 && arr[s1-1][s2]!='#' && flag[s1-1][s2]!=1)
		{
			flag[s1-1][s2] = 1;
			if(p2==s2-1 || p2==s2+1)
				calc(s1-1, s2, s1, s2, turns+1);
			else 
				calc(s1-1, s2, s1, s2, turns);
			flag[s1-1][s2] = 0;
		}
		if(s2+1 <= c && arr[s1][s2+1]!='#' && flag[s1][s2+1]!=1)
		{
			flag[s1][s2+1] = 1;
			if(p1==s1-1 || p1==s1+1)
				calc(s1, s2+1, s1, s2, turns+1);
			else 
				calc(s1, s2+1, s1, s2, turns);
			flag[s1][s2+1] = 0;
		}
		if(s2-1 >= 0 && arr[s1][s2-1]!='#' && flag[s1][s2-1]!=1)
		{
			flag[s1][s2-1] = 1;
			if(p1==s1-1 || p1==s1+1)
				calc(s1, s2-1, s1, s2, turns+1);
			else 
				calc(s1, s2-1, s1, s2, turns);
			flag[s1][s2-1] = 0;
		}
		return ;
	}
}
int main()
{
	int s1, s2;
	si(t)
	while(t--)
	{
		mini = INT_MAX;
		memset(flag, 0, sizeof(flag));
		memset(dp, -1, sizeof(flag));
		scanf("%d%d", &r, &c);
		for(i=0;i<r;i++)
			scanf("%s", arr[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(arr[i][j] == 'S')
				{
					s1 = i, s2 = j;
				}
				else if(arr[i][j] == 'E')
				{
					e1 = i, e2 = j;
				}
			}
		}
		r--;
		c--;
//		printf("%d %d %d %d\n", s1, s2, e1, e2);
		int ans = calc(s1, s2, -1, -1, 0);
		if(mini == INT_MAX)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}

