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
		int flag=0, x, y, k, n, p, c;
		sii(x, y)  
		sii(k, n)
		x-=y;
		for(int i=0;i<n;i++)
		{
			sii(p, c)
			if(p>=x && c<=k)
			{
				flag = 1;
			}
		}
		if(flag)
			cout<<"LuckyChef"<<endl;
		else 
			cout<<"UnluckyChef"<<endl;
	}
	return 0;
}

