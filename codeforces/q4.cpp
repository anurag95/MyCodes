#include<bits/stdc++.h> 
#define SI(n) scanf("%d",&n) 
#define SII(a,b) scanf("%lld%lld",&a,&b) 
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
int gcd(int a, int b)
{
	int r;
	while(b!=0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	ll flag, i, a, b, tempa, tempb;
	ll timea = 0, timeb = 0;
	SII(a, b);
	tempa = 0;
	tempb = b;
	ll lcm = (a*b)/gcd(a, b);
	flag=0;
	if(a<b)
	{
		while(tempa < lcm)
		{
			while(tempa<tempb)
			{
				tempa+=a;
				if(tempa == lcm)
				{
					timeb += a;
					flag=1;
					break;
				}
				timea+=a;
			}
			if(flag)
				break;
			timea-=a;
			timeb += tempb - tempa + a;
			timea += tempa-tempb;
			tempb+=b;
		}
		if(timea>timeb)
			printf("Dasha\n");
		else if(timeb>timea)
			printf("Masha\n");
		else    printf("Equal\n");
	}
	else
	{
		tempa = a;
		tempb = 0;
		while(tempb < lcm)
		{
			while(tempb<tempa)
			{
				tempb+=b;
				if(tempb == lcm)
				{
					timea += b;
					flag=1;
					break;
				}
				timeb+=b;
			}
			if(flag)
				break;
			timeb-=b;
			timea += tempa - tempb + b;
			timeb += tempb-tempa;
			tempa+=a;
		}
		if(timea>timeb)
			printf("Dasha\n");
		else if(timeb>timea)
			printf("Masha\n");
		else    printf("Equal\n");
	}
	return 0;
}
