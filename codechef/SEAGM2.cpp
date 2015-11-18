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
	int power[14];
	int t;
	int n, m;
	double ans, var;
	si(t)
	while(t--)
	{
		int mini = 1000000;
		memset(power, 0, sizeof(power));
		double sum=0, first=1, product[14];
		for(int i=0;i<13;i++)
			product[i] = 1;
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%lf", &var);
				while((int)var%10 == 0 && var!=0){
					var*=10;
					power[i]++;
				}
				product[i] *= (var);
				while((int)product[i]/10>0){
					product[i]/=10;
					power[i]--;
				}
			}
			if(power[i] < mini) mini = power[i];
		}
		for(int i=0;i<n;i++)
		{
			power[i] -= mini;
		}
		int fp = power[0];
		double f = product[0];
		sum = 0;
		for(int i=0;i<n;i++)
		{
			while(power[i]>0){
				product[i] /= 10;
				power[i]--;
			}
			sum += product[i];
		}
		while(fp>0){
			f /= 10;
			fp--;
		}

		if(sum < 1e-6)
			ans = 0;
		else 
			ans = f/sum;
		printf("%lf\n", ans);
	}
	return 0;
}

