#include<bits/stdc++.h>
#define SI(n) scanf("%d",&n)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SLL(n) scanf("%lld",&n)
#define SC(r) scanf("%c",&r)
#define SS(r) scanf("%s",r)
#define REPA(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define PI(n) printf("%d\n",n)
#define PII(a,b) printf("%d %d\n",a,b)
#define PLL(n) printf("%lld\n",n)
#define PC(n) printf("%c\n",n)
#define PS(n) printf("%s\n",n)
#define ll long long

using namespace std;
int main()
{
	ll n,floor=0,num=1,add=5,min=2;

	SLL(n);
	while(1)
	{
		if(n<min)
			break;
		else if((n+num)%3==0)
			floor++;

		num++;
		min+=add;
		add+=3;
	}
	PLL(floor);
	return 0;
}
