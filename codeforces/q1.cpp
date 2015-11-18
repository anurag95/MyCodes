#include<bits/stdc++.h> 
#define SI(n) scanf("%d",&n) 
#define SII(a,b) scanf("%d%d",&a,&b) 
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c) 
#define SL(n) scanf("%lld",&n) 
#define SC(r) scanf("%c",&r) 
#define SS(r) scanf("%s",r) 
#define REPA(i,a,n) for(int i=a;i<n;i++) 
#define REP(i,n) for(int i=0;i<n;i++) 
#define PI(n) printf("%d\n",n) 
#define PL(n) printf("%lld\n",n) 
#define PC(n) printf("%c\n",n) 
#define PS(n) printf("%s\n",n) 
#define ll long long
using namespace std;
int maxi(int a, int b)
{
	return a<b?a:b;
}
int main()
{
	int c1, c2, c3, c4, n, m, i;
	SI(c1);
	SI(c2);
	SI(c3);
	SI(c4);
	SII(n, m);
	int amount=0, max, temp=0;
	int bus[n], trolley[m];
	REP(i, n)
	{
		SI(bus[i]);
	}
	REP(i, n)
	{
		temp = maxi(c2, c1*bus[i]);
		if(temp+amount > c3)
		{
			amount = c3;
			break;
		}
		else    amount+=temp;
	}
	max = amount;
	amount=0;
	REP(i, m)
	{
		SI(trolley[i]);
	}
	REP(i, m)
	{
		temp = maxi(c2, c1*trolley[i]);
		if(temp+amount > c3)
		{
			amount = c3;
			break;
		}
		else    amount+=temp;
	}
	if(max + amount > c4)
		printf("%d\n", c4);
	else printf("%d\n", max+amount);
	return 0;
}
