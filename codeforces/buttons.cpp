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
	int m, n;
	sii(n, m)
	int count=0;
	if(n>=m)
	{
		while(n>m)
		{
			n--;
			count++;
		}
		printf("%d\n", count);
	}
	else {
		while(m!=n)
		{
			if(m<n)
				m++;
			else {
				if(m&1)
				{
					m = (m+1)/2;
					count++;
				}
				else m/=2;
			}
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}

