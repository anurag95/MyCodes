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
int n, co=0, su[5001][4];
int getnum(int index, int prev, int sum)
{
	if(index == 3)
	{
		if(n-sum >= prev)
		{	
	//		co++;
			su[n][3] = 1;
		}
		return su[sum][2];
	}
	int cc = 0;
	for(int j=prev; j<n; j++)
	{
		if(sum+j > n)
			break;
		if(su[sum+j][index] == 0)
			su[sum+j][index] = getnum(index+1, j, sum+j);
		cc += su[sum+j][index];
		
	}
	return cc;
}

int func(int sum, int iter, int prev)
{
	if(iter == 0)
	{
		if(sum <= prev)
			return 1;
		else return 0;
	}
	else {
		if(su[sum][iter] != 0)
			return su[sum][iter];
		for(int j=prev;j<=n;j++)
		{
			if(sum-j < 0)
				break;
			su[sum][iter] += func(sum-j, iter-1, j);
		}
		return su[sum][iter];
	}
}
int main()
{
	int t;
	si(n)
	memset(su, 0, sizeof(su));
	su[n][3] = func(n, 3, 1);
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++)
			printf("%d ", su[i][j]);
		printf("\n");
	}
	pi(su[n][3]);
	return 0;
}

