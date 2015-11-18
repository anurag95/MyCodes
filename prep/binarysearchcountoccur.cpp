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
vector<int> arr;
vector<int>::iterator low, high;
int main()
{
	int n;
	si(n);
	for(int i=0;i<n;i++)
	{
		int var;
		si(var);
		arr.pb(var);
	}
	int ele;
	si(ele);
	low = lower_bound(arr.begin(), arr.end(), ele);
	high = upper_bound(arr.begin(), arr.end(), ele);
	if(*low != ele)
		pi(0)
	else pi((int)(high-low));
	return 0;
}

