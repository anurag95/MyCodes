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
	int n, t, arr[30100], i;
	scanf("%d%d", &n, &t);
	for(i=1;i<n;i++)
		scanf("%d", &arr[i]);
	int ans = 1;
	while(ans < t)
		ans = ans+arr[ans];
	if(ans == t)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}

