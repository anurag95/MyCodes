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
	int t;
	si(t)
	while(t--)
	{
		int a, b;
		sii(a, b);
		int count=0;
		while(a!=b){
			if(a<b)
				swap(a, b);
			a/=2;
			count++;
		}
		pi(count);
	}
	return 0;
}

