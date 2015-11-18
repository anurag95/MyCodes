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
	map< string, int > M;
	map< string, int >::iterator it;
	int i, j, n, count=0;
	string str;
	si(n)
	for(i=0;i<n;i++)
	{
		cin>>str;
		M[str] += 1;
	}
	for(it=M.begin();it!=M.end();it++)
	{
		if(count < it->second)
			count = it->second;
	}
	printf("%d\n", count);
	return 0;
}

