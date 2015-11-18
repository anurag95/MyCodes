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
int arr[10000010];
int main()
{
	ll n, m, var, ans = 0, sum;
	memset(arr, -1, sizeof(arr));
	scanf("%lld%lld", &n, &m);
	while(n--)
	{
		scanf("%lld", &var);
		ll t, mod1=var, mod2=var+1;
		if(var%2 == 0)
			mod1/=2;
		else mod2/=2;
		mod1 = mod1%m;
		mod2 = mod2%m;
		sum = var%m;
		sum = (sum*mod1)%m;
		sum = (sum*mod2)%m;
		sum = (sum+m-1)%m;
		
		if(var < (m-1))
		{
			if(arr[var+1] == -1) 
			{
				ll counter = var+1, temp=1;
				while(counter >= 2)
				{
					temp = (temp*counter)%m;
					if(!temp)
						break;
					counter--;
				}
				arr[var+1] = temp;
			}
			sum = (sum+arr[var+1])%m;
		}
		ans = (ans+sum)%m;
	}
	printf("%lld\n", ans);
	return 0;
}

