#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pll(x) printf("%lld\n", x);
#define pi 3.141592
struct node {
	double x;
	double y;
	double range;
};
int main()
{
	int n, i, j;
	si(n)
	double dist;
	while(n)
	{
		node alien[n];
		scanf("%lf%lf%lf", &alien[0].x, &alien[0].y, &alien[0].range);
		for(i=1;i<n;i++)
		{
			int count;
			scanf("%lf%lf%lf", &alien[i].x, &alien[i].y, &alien[i].range);
			do {
				double x=alien[i].x, y=alien[i].y, area = pi*alien[i].range*alien[i].range;
				count=1;
				for(j=0;j<i;j++)
				{
					if(alien[j].x == -1)
						continue;
					dist = sqrt(pow(alien[i].x-alien[j].x, 2) + pow(alien[i].y-alien[j].y, 2));
					if(alien[i].range > dist || alien[j].range > dist)
					{
						x+=alien[j].x;
						y+=alien[j].y;
						count++;
						area+=(pi*alien[j].range*alien[j].range);
						alien[j].x = -1;
					}
				}
				alien[i].x = x/count;
				alien[i].y = y/count;
				alien[i].range = sqrt(area/pi);
			}while(count>1);
		}
		int ans = 0;
		for(i=0;i<n;i++)
			if(alien[i].x!=-1)
				ans++;
		printf("%d\n", ans);
		si(n)
	}
	return 0;
}

