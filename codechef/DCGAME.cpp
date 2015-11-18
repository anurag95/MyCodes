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
#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


pair<int, int> p[1000010];
int arr[1000010];
int pre[1000010], suf[1000010];
set<int> s;
set<int>::iterator it, next, prev;
int main()
{
	int m, n, k, var, i;
	scanint(n);
	scanint(m);
	for(i=0;i<n-1;i++){
		//scanf("%d", &var);
		scanint(var);
		p[i] = make_pair(var, (ll)(i+1));
	}
	scanf("%d", &var);
	p[i] = make_pair(var, (ll)(i+1));
	sort(p, p+n);
	for(i=0;i<n;i++) arr[i]=p[i].first;
	int a, ind;
	int id, id2;
	s.insert(0);
	s.insert(n+1);
	for(i=n-1;i>=0;i--){
		ind = p[i].second;
		s.insert(ind);
		it = s.find(ind);
		it++;
		next = it;
		it--; it--;
		prev = it;
		it++;
		id = (*(next)-ind)&1;
		id2 = (ind-*(prev))&1; 
//		a = (ll)(*(next)-ind)*(ind-*(prev));
		p[i].second = id*id2;
	}
	char sign, player;
	suf[n-1] = p[n-1].second;
	pre[0] = p[0].second;
	for(i=1;i<n;i++){
		pre[i] = pre[i-1]+p[i].second;
		suf[n-1-i] = suf[n-i]+p[n-1-i].second;
	}
	for(i=0;i<m;i++){
		getchar();
		scanf("%c %d %c", &sign, &k, &player);
		if(sign == '='){
			id = lower_bound(arr, arr+n, k)-arr;
			id2 = upper_bound(arr, arr+n, k)-arr;
			if(id>=n || arr[id]>k) a=0;
			else {
				if(id2>=n){
					a = pre[n-1] - ((id>0)?pre[id-1]:0);
				}
				else a = pre[id2-1]- ((id>0)?pre[id-1]:0);
			}
		}
		else if(sign == '>'){
			id = upper_bound(arr, arr+n, k)-arr;
			if(id<n && arr[id]>k){
				a = suf[id];
			}
			else a=0;
		}
		else if(sign == '<'){
			id = lower_bound(arr, arr+n, k)-arr;
			if(id<n && arr[id]>=k){
				a = (id>0)?pre[id-1]:0;
			}
			else {
				a = pre[id];
			}
		}
		if(a%2 != 0) { 
			if(player=='D') printf("D");
			else printf("C");
		}
		else {
			if(player=='D') printf("C");
			else printf("D");
		}
	}
	printf("\n");
	return 0;
}

