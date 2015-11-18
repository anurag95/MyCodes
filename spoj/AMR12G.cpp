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
	int t, n, m, k, i, j;
	int arr[50];
	char str[52];
	si(t)
	while(t--)
	{
		sii(n, m);
		si(k);
		memset(arr, 0, sizeof(arr));
		for(i=0;i<n;i++)
		{
			scanf("%s", str);
			for(j=0;j<m;j++)
			{
				if(str[j] == '*')
					arr[i]++;
			}
		}
		sort(arr, arr+n);
		for(i=0;i<k;i++)
		{
			arr[0] = m-arr[0];
			sort(arr, arr+n);
		}
		int sum=0;
		for(i=0;i<n;i++)
		{
			sum+=arr[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}

