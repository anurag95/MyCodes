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
	ll t, n, i, arr[20], var;
	ll maxprod, minprod;
	sll(t)
	while(t--)
	{
		sll(n)
		ll my=0, j=0;
		ll sign = 0;
		for(i=0;i<n;i++){
			sll(var)
			if(var == 0){
				my++;
				continue;
			}
			arr[j] = var;
			if(arr[j] < 0)
				sign++;
			j++;
		}
		n-=my;
		if(n==0){
			printf("0 0\n");
			continue;
		}
		sort(arr, arr+n);
		if(sign%2 == 0){
			maxprod = minprod = 1LL;
			ll mini = 500;
			for(i=0;i<n;i++){
				maxprod = maxprod*arr[i];
				minprod = minprod*arr[i];
				if(arr[i]<0) mini = arr[i];
			}
			if(mini == 500 && my>0) minprod=0LL;
			else if(mini == 500) minprod = arr[0];
			else {
				minprod = (minprod/mini);
			}
			printf("%lld %lld\n", maxprod, minprod);
		}
		else {
			maxprod = minprod = 1LL;
			ll mini = 500;
			for(i=0;i<n;i++){
				maxprod = maxprod*arr[i];
				minprod = minprod*arr[i];
				if(arr[i]<0) mini = arr[i];
			}
			if(n != 1){
				maxprod = (maxprod/mini);
			}
			else if(my>0) maxprod = 0LL;
			else maxprod = maxprod*1;
			printf("%lld %lld\n", maxprod, minprod);
		}
	}
	return 0;
}

