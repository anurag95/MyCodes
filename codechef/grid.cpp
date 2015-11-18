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
	int t, n;
	char arr[35][35];
	si(t)
	while(t--)
	{
		int i, j, flag = 0;
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%s", arr[i]);
		for(i=0;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(arr[i][j] != arr[i][j-1])
					break;
			}
			if(j == n)
			{
				flag = 1;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(arr[j][i] != arr[j-1][i])
					break;
			}
			if(j == n)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

