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
#define PD(n) printf("%.9lf\n",n)
#define PDD(n,c) printf("%lf %lf\n",n,c)
#define PL(n) printf("%lld\n",n)
#define PC(n) printf("%c\n",n)
#define PS(n) printf("%s\n",n)
#define ll long long
using namespace std;

double dp(double,double);
double n,w,b;
double dp1[1010][1010];

int main()
{

	SDD(w,b);
	int W=(int)w;
	int B=(int)b;
	double x=-1,y=0;
	
	REP(i,W+1)
		REP(j,B+1)
			dp1[i][j]=(double)x;
		
	REP(i,W+1)
			dp1[i][0]=(double)i;	
	REP(i,B+1)
			dp1[0][i]=(double)y;	
	
	REPA(i,1,W+1)
		REPA(j,1,B+1)
		{
			dp1[i][j]=dp((double)i,(double)j);
		}
	
/*	REPA(i,0,W+1)
		REPA(j,01,B+1)
		{
			PD(dp1[i][j]);
		}
*/	
	if(dp1[W][B]<=1 && dp1[W][B]>=0)
		PD(dp1[W][B]);
	else if(dp1[W][B]>1)
		printf("1.000000000\n");
	else
		printf("0.000000000\n");
	return 0;
}

double dp(double i,double j)
{
//	PDD(i,j);
	double cmp=0;
	int I=(int)i;
	int J=(int(j));

	if(i<=cmp)
		return cmp;
	else if(j==cmp)
		return cmp+1;
	else if(j<cmp)
		return cmp;
	else if(dp1[I][J]!=-1)
		return dp1[I][J];
	double ans=0;
	
	ans+=(i/(i+j));
	if((i+j-1!=0) && (i+j-2)!=0)
	{
		double a=(j/(i+j))*((j-1)/(i+j-1))*((j-2)/(i+j-2));
	//	PD(a);
		a=a*(double)dp(i,j-3);
	//	PD(a);	
		double b=(j/(i+j))*((j-1)/(i+j-1))*((i)/(i+j-2));
	//	PD(b);
		b=b*(double)dp(i-1,j-2);
	//	PD(b);
		ans=ans+a+b;
	//	PDD(i,ans);
	}
	return ans;
}
