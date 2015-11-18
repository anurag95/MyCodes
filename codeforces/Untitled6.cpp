#include<bits/stdc++.h>
#define SI(n) scanf("%d",&n)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SDD(a,b) scanf("%lf%lf",&a,&b)
#define SL(n) scanf("%lld",&n)
#define SC(r) scanf("%c",&r)
#define SS(r) scanf("%s",r)
#define REPA(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define PI(n) printf("%d\n",n)
#define PD(n) printf("%lf\n",n)
#define PL(n) printf("%lld\n",n)
#define PC(n) printf("%c\n",n)
#define PS(n) printf("%s\n",n)
#define ll long long
using namespace std;

double dp(double,double);
int main()
{
	double n,w,b;
//	double dp[1010][1010];
	
	
	SDD(w,b);
	
	PD(dp(w,b));
	return 0;
}

double dp(double i,double j)
{
	if(i<=0)
		return 0;
	else if(j<=0)
		return 1;
	
	double ans=0;
	
	ans+=(i/(i+j));
	
	double a=(j/(i+j))*((j-1)/(i+j-1))*((j-2)/(i+j-2));
	a=a*dp(i,j-3);
	
	double b=(j/(i+j))*((j-1)/(i+j-1))*((i)/(i+j-2));
	
	b=b*dp(i-1,j-3);
	ans=ans+a+b;
	return ans;
}
