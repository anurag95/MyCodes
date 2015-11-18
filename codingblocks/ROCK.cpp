#include<bits/stdc++.h>
using namespace std;
int dp[205][205];
int find(char str[], int start, int end)
{
	if(dp[start][end] != -1)
		return dp[start][end];
	int i, count=0, count2=0;
	for(i=start;i<=end;i++)
	{
		if(str[i] == '1')
			count++;
		else    count2++;
	}
	if(count > count2)
		return dp[start][end] = end-start+1;
	else {
		int ret=0;
		for(i=start;i<end;i++)
			ret = max(ret, find(str, start, i) + find(str, i+1, end));		 
		return dp[start][end] = ret;
	}
}
int main()
{
	int t, n, i, j;
	char str[201];
	scanf("%d", &t);
	while(t--)
	{
		for(i=0;i<205;i++)
			for(j=0;j<205;j++)
				dp[i][j] = -1;

		scanf("%d", &n);
		scanf("%s", str);
		printf("%d\n", find(str, 0, n-1));
	}
	return 0;
}

