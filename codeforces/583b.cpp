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
	int n;
	pair<int, int> p[1003];
	si(n)
	for(int i=0;i<n;i++){
		int var;
		si(var);
		p[i] = make_pair(var, 0);
	}
	int count = 0, c =0;
	while(count < n){
		for(int i=0;i<n;i++)
		{
			if(p[i].second==0 && p[i].first <= count){
				count++;
				p[i].second = 1;
			}
		}
		if(count == n)
			break;
		c++;
		for(int i=n-1;i>=0;i--)
		{
			if(p[i].second==0 && p[i].first <= count)
			{
				count++;
				p[i].second = 1;
			}
		}
		if(count == n)
			break;
		c++;
	}
	pi(c);
	return 0;
}

