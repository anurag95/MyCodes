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
#define l first
#define h second
ll n, h;
ll bit[1000010], arr[1000010];
void update(int idx, int val){
	while(idx <= n){
		bit[idx] += (ll)val;
		idx += (idx&(-idx));
	}
}
ll query(int idx){
	ll sum=0LL;
	while(idx > 0){
		sum += bit[idx];
		idx -= (idx&(-idx));
	}
	return sum;
}
void rangeupdate(int l, int h){
	update(l, 1);
	update(h+1, -1);
}
int main()
{
	int t, i;
	int x, y;
	si(t)
	while(t--)
	{
		sll(n);
		sll(h);
		for(i=0;i<=n;i++){
			bit[i] = 0;
		}
		for(i=0;i<n;i++){
			sii(x, y);
			rangeupdate(x+1, y+1);
		}
		for(i=0;i<n;i++){
			arr[i] = n-query(i+1);
		}
		ll sum = 0LL, mini;
		for(i=0;i<h;i++)
		{
			sum += arr[i];
		}
		mini = sum;
		for(i=h;i<n;i++){
			sum += (arr[i]-arr[i-h]);
			mini = (mini>sum)?sum:mini;
		}
		printf("%lld\n", mini);
	}
	return 0;
}

