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
#define x first
#define y second
ll arr[100010];
ll hash[100010], n, k;
ll ind[100010];
ll last, firs;
void func(ll a){
	if(a < 0)
		return ;
	if(a == 0){
		last = (firs);
		return ;
	}
	ll i, d=sqrt(a);
	for(i=1;i<=d;i++){
		if(((a%i)==0) && (hash[i])){
			if(((a+k)%i)==k){
				last = min(last, ind[i]);
			}
		}
		if(((a%i)==0) && ((a%(a/i))==0) && (hash[a/i])){
			if(((a+k)%(a/i)) == k){
				last = min(last, ind[a/i]);
			}
		}
	}
}
int main()
{
	ll i, j, a;
	ll count=1LL;
	ll var;
	sll(n);
	sll(k);
	for(i=0;i<n;i++){
		scanf("%lld", &arr[i]);
		ind[i] = -1LL;
	}
	memset(hash, 0, sizeof(hash));
	hash[arr[n-1]] = 1LL;
	ind[arr[n-1]] = n-1;
	last=n;
	firs = n;
	if(arr[n-1] > k)
		firs = n-1;
	for(i=n-2;i>=0;i--)
	{
		a = arr[i]-k;
		func(a);
//		if(var == n){
//			count += (n-i);
//		}
//		else {
			count += (last-i);
//		}
		hash[arr[i]] = 1;
		ind[arr[i]] = i;
		if(arr[i] > k)
			firs = i;
	}
	printf("%lld\n", count);
	return 0;
}

