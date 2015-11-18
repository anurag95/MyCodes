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
vector<int> func(int n)
{
	map<int, int> M;
	vector<int> ans;
	int d = (int)pow(n*1.0, 1.0/3.0);
	for(int i=1;i<=d;i++){
		for(int j=i;j<=d;j++){
			M[i*i*i + j*j*j] += 1;
		}
	}
	for(map<int, int>::iterator it=M.begin(); it!=M.end(); it++)
		if(it->second == 2)
			ans.pb(it->first);
	return ans;
}
int main()
{
	int t;
	si(t)
	while(t--)
	{
		int n;
		si(n)
		vector<int> v = func(n);
		for(auto i: v)
			cout<<i<<" ";
		printf("\n");

	}
	return 0;
}

