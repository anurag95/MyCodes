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
	int t, i=0;
	map<string, int> sorted;
	map<string, int> :: iterator it;
	string name;
	si(t)
	for(i=0;i<t;i++)
	{
		cin>>name;
		sorted[name]++;
	}
	for(it = sorted.begin(); it != sorted.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}

