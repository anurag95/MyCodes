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
	int i, j, n, t;
	int arr[10001], lis[10001];
	int newarr[10001];
	sii(n, t);
	for(i=0;i<n;i++)
		si(arr[i])
	int s;
	if(t <= n){
		s = n*t;
		for(i=0;i<s;i++){
			if(i>=n)
				newarr[i] = arr[i-n];
			else newarr[i] = arr[i];
		}
	}
	else {
		s = n*100;
		for(i=0;i<s;i++){
			if(i>=n)
				newarr[i] = arr[i-n];
			else newarr[i] = arr[i];
		}
	}
	// LIS in log n
	vector<int> v;
	vector<int>::iterator it;
	int k = 0;
	for(i=0;i<s;i++)
	{
		it = upper_bound(v.begin(), v.end(), newarr[i]);
		if(it == v.end()){
			v.pb(newarr[i]);
			k++;
		}
		else v[it-v.begin()] = newarr[i];
	}
	int num[301]={0};
	int mx=-1;
	for(i=0;i<n;i++)
		num[arr[i]]++;
	for(i=0;i<301;i++)
		mx = max(mx, num[i]);
	if(s != n*t)
		k += mx*(t-100);
	pi(k);

	return 0;
}
