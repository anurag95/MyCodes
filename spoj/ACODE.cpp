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
	char str[5005];
	int a, b, i, j, dp[5005];
	while(1)
	{
		scanf("%s", str);
		if(str[0] == '0')
			break;
		memset(dp, 0, sizeof(dp));
		dp[0] = dp[1] = 1;
		int l = strlen(str);
		for(i=2;i<=l;i++)
		{
			dp[i] = 0;
			a = str[i-2]-48;
			b = str[i-1]-48;
//			printf("%d\n", a*10+b);
			if(a==1 || (a==2 && b<=6))
				dp[i]+=dp[i-2];
			if(b!=0)
				dp[i] += dp[i-1];
		}
		printf("%d\n", dp[l]);
	}
	return 0;
}

