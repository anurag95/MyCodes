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
double dp[1010][1010];
double rec(double i, double j)
{
	double cmp = 0;
	int I = (int)i;
	int J = (int)j;
	if(i<=cmp)
		return cmp;
	else if(j == cmp)
		return cmp+1;
	else if(j<cmp)
		return cmp;
	else if(dp[I][J]!=-1)
		return dp[I][J];
	double ans=0;
	ans += (i/(i+j));
	if(i+j-2 > 0)
	{
		ans += (j/(i+j))*((j-1)/(i+j-1))*((j-2)/(i+j-2))*rec(i, j-3);
		ans += (j/(i+j))*((j-1)/(i+j-1))*((i)/(i+j-2))*rec(i-1, j-2);
	}
	return ans;

}
double w, b, n;
int main()
{
	SDD(w, b);
	int i, j;
	int W = (int)w;
	int B = (int)b;
	double x=-1, y=0, one=1;
	REP(i, W+1)
		REP(j, B+1)
			dp[i][j] = (double)x;
	REP(i, W+1)
		dp[i][0] = (double)one;
	REP(i, B+1)
		dp[0][i] = (double)y;
	REPA(i, 1, W+1)
		REPA(j, 1, B+1)
			dp[i][j] = rec((double)i, (double)j);
	PD(dp[W][B]);
	return 0;
}

	

