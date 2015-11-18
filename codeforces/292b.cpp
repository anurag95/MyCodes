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
	int boy[102] = {0}, girl[102] = {0};
	int g, b;
	sii(b, g);
	int var, i, nb, ng;
	si(nb)
	for(i=0;i<nb;i++)
	{
		si(var)
		boy[var] = 1;
	}
	si(ng)
	for(i=0;i<ng;i++)
	{
		si(var)
		girl[var] = 1;
	}
	for(i=0;i<1000010;i++)
	{
		if(boy[i%b] || girl[i%g])
		{
			boy[i%b] = girl[i%g] = 1;
		}
	}
	int flag=0;
	for(i=0;i<b;i++)
	{
		if(boy[i] == 0)
			flag = 1;
	}
	for(i=0;i<g;i++)
	{
		if(!girl[i])
			flag = 1;
	}
	if(flag)
		cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}

