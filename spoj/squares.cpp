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
		int i, n;
		si(n)
		int flag = 0;
		int d = sqrt(n);
		for(i=0;i<=d;i++)
		{
//			printf("%d\n", sqrt(n-i*i));
//			printf("%d\n", pow(sqrt(n-i*i), 2));
			if(pow(sqrt(n-(i*i)), 2) == n-(i*i))
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

