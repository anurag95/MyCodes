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
void matmul(int mat1[][10], int mat2[][10], size)
{
	int c[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			c[i][j] = 0;
			for(int k=0;k<size;k++)
			{
				c[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			mat1[i][j] = c[i][j];
		}
	}
}
int[][] mypow(int mat[][10], int n, size)
{
	int res[size][size] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	while(n)
	{
		if(n&1)
			matmul(res, mat, size);
		matmul(mat, mat, size);
		n>>=1;
	}
	return res;
}
int main()
{
	
	return 0;
}

