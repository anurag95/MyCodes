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
	int a, b, aa[20], bb[20];
	while(1)
	{
		sii(a, b)
		if(a==0 && b==0)
			break;
		for(int i=0;i<a;i++)
			si(aa[i])
		for(int i=0;i<b;i++)
			si(bb[i])
		sort(aa, aa+a);
		sort(bb, bb+b);
		if(aa[0] < bb[1])
			printf("Y\n");
		else printf("N\n");
	}
	return 0;
}

