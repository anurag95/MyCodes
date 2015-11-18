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
const double C = 1e-9;
struct node {
	double base;
	double h;
	double w;
	double b;
};
int n;
node cist[50010];
int find(double H, double vol)
{
	double myvol = 0.0;
	int i;
	for(i=0;i<n;i++)
	{
		if(cist[i].base+cist[i].h+C <= H)
			myvol+= (double)(cist[i].w*cist[i].b*cist[i].h);
		else if(cist[i].base+C <= H)
			myvol+= (double)cist[i].w*(double)cist[i].b*(double)(H-cist[i].base);
	}
//	printf("%lf\n", myvol);
	if(myvol +C == vol)
		return 0;
	else if(myvol+C < vol)
	{
		return 1;
	}
	else return -1;
}
int main()
{
	int t, i;
	double vol;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf", &cist[i].base, &cist[i].h, &cist[i].w, &cist[i].b);
		}
		scanf("%lf", &vol);
		int flag=0;
		double low=0.0, high=1000001.0, mid;
		if(find(1000001.0, vol) > 0)
			printf("OVERFLOW\n");
		else {
			int count=37;
			while(count--)
			{
				mid = (low+high)/2.0;
		//		printf("%lf ", mid);
				int a=find(mid, vol);
				if(a>0)
					low = mid;
				else high = mid;
			}
			printf("%.2lf\n", mid+C);
		}
	}
	return 0;
}

