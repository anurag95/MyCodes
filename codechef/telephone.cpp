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
	int t, arr[100010], wrong[100010];
	si(t)
	while(t--)
	{
		memset(wrong, 0, sizeof(wrong));
		int n;
		scanf("%d", &n);
		si(arr[0]);
		for(int i=1;i<n;i++)
		{
			scanf("%d", &arr[i]);
			if(arr[i] != arr[i-1])
			{
				wrong[i] = wrong[i-1] = 1;
			}
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(wrong[i] == 1)
				count++;
		}
		printf("%d\n", count);
	}	
	return 0;
}

