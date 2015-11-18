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
	int t;
	si(t)
	char str[100010];
	while(t--)
	{
		int flag = 0;
		int ind;
		scanf("%s", str);
		int l = strlen(str);
		for(int i=0;i<=(l/2);i++)
		{
			if(str[i] != str[l-1-i])
			{
				flag = 1;
				ind = i;
				break;
			}
		}
		if(!flag)
			printf("YES\n");
		else {
			int flag2 = 0;
			for(int i=ind;i<=(l/2);i++)
			{
				if(str[i] != str[l-2-i])
				{
					flag2 = 1;
					break;
				}
			}
			if(!flag2)
				printf("YES\n");
			else {
				int flag3 = 0;
				for(int i=ind+1;i<=(l/2);i++)
				{
					if(str[i] != str[l-i])
					{
						flag3 = 1;
						break;
					}
				}
				if(!flag3)
					printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}

