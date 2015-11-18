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
int arr[100010];
int hash[100010];
int main()
{
	int i, n, k, j;
	ll count;
	sii(n, k);
	count = (ll)n*(ll)(n+1)/2;
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	hash[arr[0]] = 1;
	for(i=n-1;i>0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]%arr[i] == k){
				count = count - (ll)(j+1)*(n-i);
//				count = count - (ll)(n-i-1);
				break;
			}
		}
	}
	printf("%lld\n", count);
	return 0;
}

