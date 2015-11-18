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
	ll T1, T2, t1, t2;
	si(t)
	while(t--)
	{
		double area = 0;
		scanf("%lld%lld%lld%lld", &T1, &T2, &t1, &t2);
		if(T1<T2)
		{
			T1 = T2+T1-(T2=T1);
			t1 = t2+t1-(t2=t1);
		}
		if(t1>T2)
			area = (double)(T2*T2/2.0);
		else area = (double)((T2*T2 - (T2-t1)*(T2-t1))/2.0);
		if(T2+t2 <= T1)
			area += (double)(t2*T2);
		else {
			area += (double)(T2*(T1-T2));
			if(t2-T1 >= 0)
				area += (double)(T2*T2/2.0);
			else area += (double)(T2*T2 - (T1-t2)*(T1-t2))/2.0;
		}
		area = area/(T1*T2);
		printf("%lf\n", area);
	}
	return 0;
}

