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
//	int t;
	int n, m, arr[101][101];
//	si(t);
//	while(t--)
//	{
		sii(n, m)
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				si(arr[i][j])
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!j)
					arr[i][j] += min(arr[i-1][j], arr[i-1][j+1]); 
				else if(j == m-1)
					arr[i][j] += min(arr[i-1][j], arr[i-1][j-1]);
				else 
					arr[i][j] += min(arr[i-1][j], min(arr[i-1][j+1], arr[i-1][j-1]));
			}
		}
		int max = INT_MAX;
		for(int j=0;j<m;j++)
			if(max > arr[n-1][j])
				max = arr[n-1][j];
		pi(max)
//	}
	return 0;
}

