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
	ll n, i=0, arr[33];
	sll(n)
	if(!n)
		printf("0\n");
	else {
		while(n!=0)
		{
			if(n>0)
			{
				arr[i++] = n%2;
				n/=2;
				n = -n;
			}
			else {
				ll m = -n;
				if(m%2==0){
					arr[i++]=0;
					m/=2;
				}
				else {
					arr[i++]=1;
					m = m/2 + 1;
				}
				n=m;
			}
		}
		for(ll j=i-1;j>=0;j--)
			printf("%lld", arr[j]);
		printf("\n");
	}
	return 0;
}

