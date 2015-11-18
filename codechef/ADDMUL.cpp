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
ll arr[1000010];
ll seg[1000010], mult[1000010], add[1000010], mark[1000010];
void buildtree(ll start, ll end, ll i){
	if(start == end){
		seg[i] = arr[start];
		return ;
	}
	ll mid = (start+end)/2;
	buildtree(start, mid, 2*i+1);
	buildtree(mid+1, end, 2*i+2);
	seg[i] = (seg[2*i+1]+seg[2*i+2])%mod;
}

ll get(ll s, ll e, ll x, ll y, ll i){
	if(add[i]!=0 || mult[i]!=1){
		seg[i] = ((seg[i]*mult[i])%mod + ((e-s+1)*add[i])%mod)%mod;
		if(s != e){
			add[2*i+1] = (add[2*i+1]*mult[i] + add[i])%mod;
			mult[2*i+1] = (mult[2*i+1]*mult[i])%mod;
			add[2*i+2] = (add[2*i+2]*mult[i] + add[i])%mod;
			mult[2*i+2] = (mult[2*i+2]*mult[i])%mod;
		}
		add[i] = 0;
		mult[i] = 1;
	}
	if(x>e || y<s)
		return 0;
	if(s>=x && e<=y){
		return seg[i];
	}
	ll mid = (s+e)/2;
	return (get(s, mid, x, y, 2*i+1)%mod + get(mid+1, e, x, y, 2*i+2)%mod)%mod;
}
void sum(ll s, ll e, ll x, ll y, ll v, ll i){
	if(add[i]!=0 || mult[i]!=1){
		seg[i] = ((seg[i]*mult[i])%mod + ((e-s+1)*add[i])%mod)%mod;
		if(s != e){
			add[2*i+1] = (add[2*i+1]*mult[i] + add[i])%mod;
			mult[2*i+1] = (mult[2*i+1]*mult[i])%mod;
			add[2*i+2] = (add[2*i+2]*mult[i] + add[i])%mod;
			mult[2*i+2] = (mult[2*i+2]*mult[i])%mod;
		}
		add[i] = 0;
		mult[i] = 1;
	}
	if(x>e || y<s || s>e)
		return ;
	if(s>=x && e<=y){
		seg[i] += ((e-s+1)*v)%mod;
		seg[i] = seg[i]%mod;
		if(e != s){
			add[2*i+1] += v;
			add[2*i+2] += v;
		}
		return ;
	}
	ll mid = (s+e)/2;
	sum(s, mid, x, y, v, 2*i+1);
	sum(mid+1, e, x, y, v, 2*i+2);
	seg[i] = (seg[2*i+1]+seg[2*i+2])%mod;
	return ;
}
void mul(ll s, ll e, ll x, ll y, ll v, ll i){
	if(add[i]!=0 || mult[i]!=1){
		seg[i] = ((seg[i]*mult[i])%mod + ((e-s+1)*add[i])%mod)%mod;
		if(s != e){
			add[2*i+1] = (add[2*i+1]*mult[i] + add[i])%mod;
			mult[2*i+1] = (mult[2*i+1]*mult[i])%mod;
			add[2*i+2] = (add[2*i+2]*mult[i] + add[i])%mod;
			mult[2*i+2] = (mult[2*i+2]*mult[i])%mod;
		}
		add[i] = 0;
		mult[i] = 1;
	}
	if(x>e || y<s || s>e)
		return ;
	if(s>=x && e<=y){
		seg[i] = (seg[i]*v)%mod; 
		if(e != s){
			mult[2*i+1] = (mult[2*i+1]*v)%mod;
			mult[2*i+2] = (mult[2*i+2]*v)%mod;
			add[2*i+1] = (add[2*i+1]*v)%mod;
			add[2*i+2] = (add[2*i+2]*v)%mod;
		}
		return ;
	}
	ll mid = (s+e)/2;
	mul(s, mid, x, y, v, 2*i+1);
	mul(mid+1, e, x, y, v, 2*i+2);
	seg[i] = (seg[2*i+1]+seg[2*i+2])%mod;
	return ;
}
void sett(ll s, ll e, ll x, ll y, ll v, ll i){
	if(add[i]!=0 || mult[i]!=1){
		seg[i] = ((seg[i]*mult[i])%mod + ((e-s+1)*add[i])%mod)%mod;
		if(s != e){
			add[2*i+1] = (add[2*i+1]*mult[i] + add[i])%mod;
			mult[2*i+1] = (mult[2*i+1]*mult[i])%mod;
			add[2*i+2] = (add[2*i+2]*mult[i] + add[i])%mod;
			mult[2*i+2] = (mult[2*i+2]*mult[i])%mod;
		}
		add[i] = 0;
		mult[i] = 1;
	}
	if(x>e || y<s || s>e)
		return ;
	if(s>=x && e<=y){
		seg[i] = ((e-s+1)*v)%mod; 
		if(e != s){
			mult[2*i+1] = 0;
			mult[2*i+2] = 0;
			add[2*i+1] = v;
			add[2*i+2] = v;
		}
		return ;
	}
	ll mid = (s+e)/2;
	sett(s, mid, x, y, v, 2*i+1);
	sett(mid+1, e, x, y, v, 2*i+2);
	seg[i] = (seg[2*i+1]+seg[2*i+2])%mod;
}
int main()
{
	memset(add, 0, sizeof(add));
	for(ll i=0;i<1000010;i++)
		mult[i] = 1;
	ll n, q, query, x, y, v;
	sll(n);
	sll(q);
	for(ll i=0;i<n;i++){
		scanf("%lld", &arr[i]);
		arr[i] = arr[i]%mod;
	}
	buildtree(0, n-1, 0);
	for(ll i=0;i<q;i++)
	{
		sll(query);
		sll(x);
		sll(y);
		x--;
		y--;
		if(query == 4){
			printf("%lld\n", get(0, n-1, x, y, 0));
			continue;
		}
		sll(v);
		if(query == 1)
			sum(0, n-1, x, y, v, 0);
		else if(query == 2)
			mul(0, n-1, x, y, v, 0);
		if(query == 3)
			sett(0, n-1, x, y, v, 0);
	}
	return 0;
}

