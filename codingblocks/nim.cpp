/*
   nim game
*/

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
ll x,m;
ll calcxor(ll t)
{
	if(t%4==1)
		return 1;
	else if(t%4==2)
		return t+1;
	else if(t%4==3)
		return 0;
	else
		return t;
}
int main()
{
	int n;
	si(n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&m);
		ll temp=calcxor(x+m-1);
		ll temp2=calcxor(x-1);
		ans^=temp^temp2;
	}
	if(ans==0)
		printf("bolik\n");
	else
		printf("tolik\n");
	return 0;
}
