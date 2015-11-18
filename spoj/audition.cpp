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
int cumu[1000010];
int main()
{
	int t, n, i, j, k, numk, ind, count1, count2;
	ll ans;
	char str[1000010];
	si(t)
	while(t--)
	{
		si(n)
		si(k)
		k--;
		scanf("%s", str);
		cumu[0] = (str[0]=='1')?1:0;
		for(i=1;i<n;i++)
		{
			if(str[i] == '1')
				cumu[i] = cumu[i-1]+1;
			else cumu[i] = cumu[i-1];
		}
		i = j = ind = 0;
		while(j<n)
		{
			if(i == n)
				break;
			while(cumu[j] < (cumu[i]+k))
				j++;
			ind = j;
			while(cumu[j] == (cumu[i]+k))
			{
				ans++;j++;
			}
			j = ind;
			i++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

