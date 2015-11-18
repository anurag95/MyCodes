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
	int a, b;
	scanf("%d%d", &a, &b);
	if(a == b)
		printf("infinity\n");
	else if(a<b)
		printf("0\n");
	else {
		int swap;
		if(a>b)
		{
			swap = a;
			a = b;
			b = swap;
		}
		int count=0;
		int i;
		int d = sqrt(b);
		for(i=1;i<d;i++)
		{
			if((b-a)%i == 0)
			{
				if(i<=a)
					count+=1;
				else count += 2;
			}
		}
		if((d*d)==(b-a) && (b-a)%d==0 && d>a)
			count+=1;
		else if((b-a)%d==0 && d>a)
			count+=2;
		printf("%d\n", count);
	}
	return 0;
}

