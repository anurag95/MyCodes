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
	int n, arr[3002], i;
	si(n)
	for(i=0;i<n;i++)
		si(arr[i]);
	sort(arr, arr+n);
	int count = 0;
//	for(i=0;i<n;i++)
//		printf("%d ", arr[i]);
//	printf("\n");
	for(i=1;i<n;)
	{
		if(arr[i] <= arr[i-1]){
			arr[i]++;
			count++;
		}
		else i++;
	}
	printf("%d\n", count);
	return 0;
}

