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
	int len, t, i;
	vector<int> same, diff;
	string a, b;
	sii(len, t);
	cin>>a;
	cin>>b;
	for(i=0;i<len;i++)
	{
		if(a[i] == b[i])
			same.pb(i);
		else diff.pb(i);
	}
	if(diff.size() > 2*t)
		pi(-1)
	else {
		int l = diff.size();
		for(i=0;i<l/2;i++)
		{
			a[diff[i]] = (b[diff[i]]);
		}
		for(i=0;i<l/2;i++)
		{
			b[diff[i]] = (a[diff[i]]);
		}
		t-=l/2;
		i=0;
		int y=0;
		for(i=0;i<same.size();i++)
		{
			a[same[i]] = (a[same[i]] == 'a')?'b':'a';
			b[same[i]] = (b[same[i]] == 'a')?'b':'a';
			t--;
			if(t==0){
				y = 1;
				break;
			}
		}
		if(y)
			cout<<a<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}

