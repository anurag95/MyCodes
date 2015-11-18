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
	int i, n;
	double w, arr[200003];
	double x;
	scanf("%d", &n);
	scanf("%lf", &w);
	for(i=0;i<2*n;i++)
		scanf("%lf", &arr[i]);
	sort(arr, arr+2*n);
	if(2*arr[0] <= arr[n])
	{
		if(3*n*arr[0] <= w)
			x = 3*n*arr[0];
		else x = ((double)w/(3*n))*3*n;
	}
	else {
		if((double)3*n*arr[n]/2 <= w)
			x = (double)3*n*arr[n]/2;
		else x = ((double)w/(3*n))*3*n;
	}
	printf("%lf\n", x);
	return 0;
}

