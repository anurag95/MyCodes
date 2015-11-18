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
char str[100010];
ll n, m, a, b, q;
ll arr[100010][3], prefix[100010];
void update()
{
	ll i, j, k;
	memset(arr, 0, sizeof(arr));
	prefix[0] = str[0]-'0';
	for(i=1;i<n;i++)
		prefix[i] = prefix[i-1] + str[i]-'0';
	for(i=0;i<n;i++)
	{
		for(k=0;k<3;k++)
		{
			arr[i+1][k] = arr[i][k];
		}
		arr[i+1][(prefix[i])%3]++; 
	} 
}
ll C(ll n){
	return (ll)(n*(n-1))/2;
}
int main()
{
	ll sum;
	scanf("%lld%lld", &n, &m);
	scanf("%s", str);
	update();
	while(m--)
	{
		scanf("%lld%lld%lld", &q, &a, &b);
		if(q == 1)
		{
			str[a-1] = b+'0';
			update();
		}
		else {
			ll x, y, z;
			x = arr[b][0]-arr[a-1][0];
			y = arr[b][1]-arr[a-1][1];
			z = arr[b][2]-arr[a-1][2];
			if(prefix[a-2]%3 == 2)
				swap(x, z);
			else if(prefix[a-2]%3 == 1)
				swap(x, y);
			sum = (ll)x;
			sum += C(x);
			sum += C(y);
			sum += C(z);
//			printf("%d %d %d\n", x, y, z);
			printf("%lld\n", sum);
		}
	}
	return 0;
}

