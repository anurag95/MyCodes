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
	char str[100010], a[100010], b[100010];
	char table[5][5] = {{1,0,1,1,0}, {0,1,0,1,1}, {1,0,1,0,1}, {1,1,0,1,0}, {0,1,1,0,1}};
	char table2[5][5] = {{1,1,0,0,1}, {1,1,1,0,0}, {0,1,1,1,0}, {0,0,1,1,1}, {1,0,0,1,1}};
	int t, i;
	int arr[][]
	si(t)
	while(t--)
	{
		int where=0;
		scanf("%s", str);
		int flag = 0;
		for(i=1;str[i]!='\0';i++)
		{
			if(table[str[i-1]-65][str[i]-65] == 0)
			{
				flag=1;
				break;
			}
			a[i-1] = [str[i-1]-65]
		}
		if(flag)
		{
			flag=0;
			for(i=1;str[i]!='\0';i++)
			{
				if(table2[str[i-1]-65][str[i]-65] == 0)
				{
					flag=1;
					break;
				}
			}
			if(flag)
		}
		else {
			
		}
	}
	return 0;
}

