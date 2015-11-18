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
	int n, a[1000], b[1000];
	si(n)
	int var, p[1000];
	for(int i=0;i<n;i++)
		si(a[i])
	b[0] = a[0];
	int k = 0;
	for(int i=0;i<n;i++)
	{
	/*	if(a[i] > b[k])
		{
			b[++k] = a[i];
			continue;
		}
	*/	int l=1, r=k;
		while(l<=r)
		{
			int mid = l + (r-l)/2;
			if(a[b[mid]] < a[i])
				l = mid+1;
			else r = mid-1;
		}
		b[l] = i;
		p[i] = b[l-1];
		if(l > k)
			k = l;
	}
	pi(k+1);
	int ind = b[k];
	for(int i=k-1;i>=0;i--){
		cout<<a[ind]<<" ";
		ind = p[ind];
	}
	cout<<endl;
	return 0;
}

