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
	int n, arr[102][102];
	si(n)
	int flag, i, j, count, ans[102], m=0;
	for(i=0;i<n;i++)
	{
		flag = 0;
		for(j=0;j<n;j++)
		{
			scanf("%d", &arr[i][j]);
			if(arr[i][j]>0 && arr[i][j]!=2)
				flag = 1;
		}
		if(flag == 0)
			ans[count++] = i+1;
	}
	printf("%d\n", count);
	if(count > 0)
	{
		printf("%d", ans[0]);
	for(i=1;i<count;i++)
		printf(" %d", ans[i]);
	printf("\n");
	}
	return 0;
}

