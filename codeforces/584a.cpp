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
	int n, t;
	int arr[103];
	sii(n, t);
	if(t < 10){
		arr[0] = t;
		for(int i=1;i<n;i++)
			arr[i] = 0;
		for(int i=0;i<n;i++)
			printf("%d", arr[i]);
		printf("\n");
	}
	else {
		if(n == 1)
			pi(-1)
		else {
			arr[0] = 1;
			arr[1] = 0;
			for(int i=2;i<n;i++)
				arr[i] = 0;
			for(int i=0;i<n;i++)
				printf("%d", arr[i]);
			printf("\n");
		}
	}
	return 0;
}

