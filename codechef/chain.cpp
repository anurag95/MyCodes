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
	char str[100010];
	si(t)
	while(t--)
	{
		scanf("%s", str);
		int c1=0, c2=0;
		for(int i=0;str[i];i++)
		{
			if(i%2==0 && str[i]!='-')
				c1++;
			else if(i%2==1 && str[i]!='+')
				c1++;
		}
		for(int i=0;str[i];i++)
		{
			if(i%2==1 && str[i]!='-')
				c2++;
			else if(i%2==0 && str[i]!='+')
				c2++;
		}
		printf("%d\n", min(c1, c2));
	}
	return 0;
}

