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
	char op;
	long long n, a, res;

	scanf("%lld", &n );
	while (n--) 
	{
		op = 0;
		scanf("%lld", &res);
		while (1) 
		{
			scanf("%s", &op);
			if(op=='=') 
				break;
			scanf("%lld", &a);
			switch(op) 
			{
				case '+':
					res += a;
					break;
				case '-':
					res -= a;
					break;
				case '*':
					res *= a;
					break;
				case '/':
					res /= a;
					break;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
