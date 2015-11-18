#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int g,t,a,d, matches, teams;
	scanf("%lld%lld%lld%lld", &g, &t, &a, &d);
	while(g != -1)
	{
		teams = g*a+d;
		long long int temp = teams, b = 1LL;
		while(teams>b)
			b<<=1;
		teams = b-teams;
		matches = b-1 + (g*t*(t-1))/2;
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g,a,t,d,matches,teams);
		scanf("%lld%lld%lld%lld", &g, &t, &a, &d);
	}
	return 0;
}
