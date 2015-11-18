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
	ll x, y, s;
	sll(x)
	sll(y)
	sll(s)
	if(x<0)
		x = -x;
	if(y<0)
		y = -y;
	if(s<(x+y))
		cout<<"No"<<endl;
	else if((s-x-y)%2 == 1)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}

