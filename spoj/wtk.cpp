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
int find(int n, int k)
{
	if(n==1)
		return 1;
	else return (find(n-1,k+1)+k-1)%n+1;
}
int main()
{
	int n, t;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", find(n, 1));
	}
	return 0;
}

