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
	int t, n, var;
	si(t)
	while(t--)
	{
		int count = 0, flag = 0, mini = INT_MAX;
		si(n)
		for(int i=0;i<n;i++)
		{
			si(var)
			mini = min(mini, var);
			if(var >= 2)
				count += var;
			else flag = 1;
		}
		if(flag)
			printf("-1\n");
		else {
			mini -= 2; 
			printf("%d\n", count - mini);
		}
	}
	return 0;
}

