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
	int l, j;
	char a[200010], b[200010];
	int arr1[128][128];// arr2[128][128];
	memset(arr1, -1, sizeof(arr1));
	si(l)
	scanf("%s", a);
	scanf("%s", b);
	int x=-1, y=-1, c=0;
	int flag = 0, flag2 = 0;
	for(int i=0;i<l;i++)
	{
		if(a[i] == b[i])
			continue;
		c++;
		for(j=95;j<125;j++)
		{
			if(arr1[b[i]][j] != -1)
			{
				if(j == a[i])
				{
					flag = 1;
					x = arr1[b[i]][j];
					y = i;
				}
				else if(!flag)
				{
					flag2 = 1;
					x = arr1[b[i]][j];
					y = i;
				}
			}
		}
		for(j=95;j<125;j++)
		{
			if(arr1[j][a[i]] != -1)
			{
				if(j == b[i])
				{
					flag = 1;
					x = arr1[j][a[i]];
					y = i;
				}
				else if(!flag)
				{
					flag2 = 1;
					x = arr1[j][a[i]];
					y = i;
				}
			}
		}
/*		if(arr1[b[i]][a[i]] != -1)
		{
			x = arr1[a[i]][b[i]];
			y = i;
			flag = 1;
		}
		else if(!flag)
		{
			for(int j=95;j<125;j++)
				if(arr1[a[i]])
			flag2 = 1;
			x = arr2[a[i]][b[i]];
			y = i;
		}
		else if(!flag && arr1[a[i]][b[i]] != -1)
		{
			flag2 = 1;
			x = arr1[a[i]][b[i]];
			y = i;
		}
*/
		arr1[a[i]][b[i]] = i;
//		arr1[b[i]][a[i]] = i;
	}
	if(flag)
		printf("%d\n", c-2);
	else if(flag2)
		printf("%d\n", c-1);
	else 
		printf("%d\n", c);
	if(x!=-1)
		printf("%d %d\n", x+1, y+1);
	else
		printf("%d %d\n", x, y);
	return 0;
}

