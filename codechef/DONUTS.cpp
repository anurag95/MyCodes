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
	int t, n, m, i, arr[20002];
	si(t)
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(i=0;i<m;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+m);
		ll count=0;
/*		for(i=0;i<m/2;i++)
		{
			if(arr[i] == 1)
				count += (ll)1;
			else count += (ll)2;
		}
*/		i=0;
		while(count < m-1){
			if(arr[i]>0){
				arr[i]--;
				count++;
			}
			else {
				m--;
				i++;
			}
		}
		printf("%lld\n", count);
	}
	return 0;
}

