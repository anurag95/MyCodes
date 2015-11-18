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
		ll j, i, num[3], var, m, maxi[3], max = LLONG_MAX;
		for(i=0;i<3;i++)
			maxi[i] = INT_MIN;
		sll(num[0])
		sll(num[1])
		sll(num[2])
		sll(m)
		for(j=0;j<3;j++)
		{
			for(i=0;i<num[j];i++)
			{
				sll(var)
				if(var > maxi[j])
					maxi[j] = var;
			}
		}
		while(m--)
		{
			sort(maxi, maxi+3);
//			if(max > maxi[2])
//				max = maxi[2];
		//	for(i=0;i<3;i++)
		//		printf("%lld ", maxi[i]);
		//	printf("\n");
			maxi[2]/=2;
//			maxi[0]++;
//			maxi[1]++;
		}
		sort(maxi, maxi+3);
//		if(max > maxi[2])
//			max = maxi[2];
		printf("%lld\n", maxi[2]);
	}
	return 0;
}

