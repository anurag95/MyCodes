#include<bits/stdc++.h>
#define ll long long
using namespace std;

char letters[12][2] = {{'c', 'e'}, {'c', 'h'}, {'c', 'f'}, {'e', 'c'}, {'e', 'h'}, {'e', 'f'}, {'h', 'c'}, {'h', 'e'}, {'h', 'f'}, {'f', 'e'}, {'f', 'h'}, {'f', 'c'}};
char str[1000010];
ll dp[12][3][1000010];
int main()
{
	char start, end;
	ll i, j, k, a, b;
	scanf("%s", str);
	ll l = (ll)strlen(str);
	for(i=0;i<12;i++)
	{
		a = b = 0;
		start = letters[i][0];
		end = letters[i][1];
		if(str[0] == start) a++;
		else if(str[0] == end) b++;
		dp[i][0][0] = (start==str[0])?1:0;
		dp[i][1][0] = (end==str[0])?1:0;
		dp[i][2][0] = 0;
		for(j=1;j<l;j++)
		{
			if(str[j] == start)
			{
				dp[i][0][j] = ++a;
				dp[i][1][j] = b;
				dp[i][2][j] = dp[i][2][j-1];
			}
			else if(str[j] == end)
			{
				dp[i][0][j] = a;
				dp[i][1][j] = ++b;
				dp[i][2][j] = dp[i][2][j-1] + a;
			}
			else {
				dp[i][0][j] = a;
				dp[i][1][j] = b;
				dp[i][2][j] = dp[i][2][j-1];
			}
		}
	}
	ll q;
	scanf("%lld", &q);
	while(q--)
	{
		getchar();
		scanf("%c %c %lld%lld", &start, &end, &a, &b);
		if((start == end) || (a == b))
		{
			printf("0\n");
			continue;
		}
		ll find;
		for(i=0;i<12;i++)
		{
			if(letters[i][0] == start && letters[i][1] == end)
			{
				find = i;
				break;
			}
		}
/*		for(i=0;i<3;i++)
		{
			for(j=0;j<l;j++)
				cout<<dp[find][i][j]<<" ";
			cout<<endl;
		}
*/ //		printf("find %d\n", find);
		ll ans = dp[find][2][b-1];
		if(a>1)  ans-= dp[find][2][a-2];
//		cout<<ans<<endl;
		ll var = (a>1)?dp[find][0][a-2]:0;
		ll var2 = (a>1)?dp[find][1][a-2]:0;
		ans = ans - var*(dp[find][1][b-1] - var2);
//		cout<<var<<" "<<var2<<" "<<endl;
		printf("%lld\n", ans);
	}
	return 0;
}

