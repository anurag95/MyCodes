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
	ll i, t;
	ll type, l;
	ll ans, ans2;
	char arr[100010], f, s;
	sll(t)
	while(t--)
	{
		sll(type);
		scanf("%s", arr);
		l = (ll)strlen(arr);
		ll c = 0;
		for(i=0;i<l;i++)
		{
			if(arr[i] == 'B')
				c++;
			else c--;
		}
		if(abs(c) > 1)
			printf("-1\n");
		else if(type == 0){
			f = 'B'; s = 'G';
			stack<ll> a, b; 
			ans = 0;
			for(i=0;i<l;i++)
			{
				if(i%2==0 && arr[i]==f)
					continue;
				if(i%2==1 && arr[i]==s)
					continue;
				if(arr[i] == f){
					if(!b.empty()) { ans = ans + (ll)pow(abs(i-b.top()), type); b.pop(); }
					else a.push(i);
				}
				else if(arr[i] == s){
					if(!a.empty()) { ans = ans + (ll)pow(abs(i-a.top()), type); a.pop(); }
					else b.push(i);
				}	
			}
			if(!a.empty() || !b.empty())
				ans = LLONG_MAX;
			while(!a.empty()) a.pop();
			while(!b.empty()) b.pop();
			ans2 = 0;
			f = 'G'; s = 'B';
			for(i=0;i<l;i++)
			{
				if(i%2==0 && arr[i]==f)
					continue;
				if(i%2==1 && arr[i]==s)
					continue;
				if(arr[i] == f){
					if(!b.empty()) { ans2 = ans2 + (ll)pow(abs(i-b.top()), type); b.pop(); }
					else a.push(i);
				}
				else if(arr[i] == s){
					if(!a.empty()) { ans2 = ans2 + (ll)pow(abs(i-a.top()), type); a.pop(); }
					else b.push(i);
				}
			}
			if(!a.empty() || !b.empty())
				ans2 = LLONG_MAX;

			printf("%lld\n", min(ans, ans2));
		}
		else {
			f = 'B'; s = 'G';
			queue<ll> a, b; // a stores when we get f
			ans = 0;
			for(i=0;i<l;i++)
			{
				if(i%2==0 && arr[i]==f){
					if(!b.empty()){
						ans = ans + (ll)pow(abs(i-b.front()), 1); b.pop(); b.push(i);
					}
					continue;
				}
				if(i%2==1 && arr[i]==s){
					if(!a.empty()){
						ans = ans + (ll)pow(abs(i-a.front()), 1); a.pop(); a.push(i);
					}
					continue;
				}
				if(arr[i] == f){
					if(!b.empty()) { ans = ans + (ll)pow(abs(i-b.front()), 1); b.pop(); }
					else a.push(i);
				}
				else if(arr[i] == s){
					if(!a.empty()) { ans = ans + (ll)pow(abs(i-a.front()), 1); a.pop(); }
					else b.push(i);
				}	
			}
			if(!a.empty() || !b.empty())
				ans = LLONG_MAX;
			while(!a.empty()) a.pop();
			while(!b.empty()) b.pop();
			ans2 = 0;
			f = 'G'; s = 'B';
			for(i=0;i<l;i++)
			{
				if(i%2==0 && arr[i]==f){
					if(!b.empty()){
						ans2 = ans2 + (ll)pow(abs(i-b.front()), 1); b.pop(); b.push(i);
					}
					continue;
				}
				if(i%2==1 && arr[i]==s){
					if(!a.empty()){
						ans2 = ans2 + (ll)pow(abs(i-a.front()), 1); a.pop(); a.push(i);
					}
					continue;
				}
				if(arr[i] == f){
					if(!b.empty()) { ans2 = ans2 + (ll)pow(abs(i-b.front()), 1); b.pop(); }
					else a.push(i);
				}
				else if(arr[i] == s){
					if(!a.empty()) { ans2 = ans2 + (ll)pow(abs(i-a.front()), 1); a.pop(); }
					else b.push(i);
				}
			}
			if(!a.empty() || !b.empty())
				ans2 = LLONG_MAX;

			printf("%lld\n", min(ans, ans2));
		}
	}
	return 0;
}

