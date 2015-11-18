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
	int n, d, a, b;
	int arr[20010] = {0};
	si(n)
	si(d)
	while(n--)
	{
		scanf("%d%d", &a, &b);
		if(arr[b] == 1)
			break;
		arr[b] = 1;
	}
	if(n<0)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}

