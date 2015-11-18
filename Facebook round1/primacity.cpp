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
int num[10000002], primacity[10000002];
void create()
{
	int k, i;
	memset(num, 0, sizeof(num));
	memset(primacity, 0, sizeof(primacity));
//	for(int l=0;l<10;l++)
//		printf("%d ", num[l]);
	num[0] = 0;
	num[1] = 0;
	for(i=2;i<10000002;i++)
	{
		if(num[i] == 0)
		{
	//		sieve[k++] = i;
			for(int j=i;j<10000002;j+=i) {
				num[j] = 3;
				primacity[j]++;
			}
		}
	}
//	for(int l=0;l<10;l++)
//		printf("%d ", primacity[l]);
}
int main()
{
	create();
	int t, c=0;
	si(t)
	while(t--)
	{
		c++;
		int k, a, b, count=0;
		scanf("%d%d%d", &a, &b, &k);
		for(int i=a;i<=b;i++)
		{
			if(primacity[i] == k)
				count++;
		}
		printf("Case #%d: %d\n", c, count);
	}
	return 0;
}

