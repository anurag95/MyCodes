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
	int n, arr[1200];
	si(n)
	for(int i=0;i<n;i++)
		si(arr[i])
	sort(arr, arr+n);
	if(arr[0] == 1)
		printf("-1\n");
	else printf("1\n");
	return 0;
}
