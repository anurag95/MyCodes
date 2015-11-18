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
	int t, arr[1000010];
	si(t)
	while(t--)
	{
		int i, j, n, k;
		int m;
		sii(n, k);
		m = n/2;
		for(i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n);
		int maxi = INT_MIN, mini=INT_MAX;
		i=0; j=n-1;
		while(i<j){
			int var = arr[i]+arr[j];
			maxi = max(maxi, var);
			mini = min(mini, var);
			i++; j--;
		}
		int ans = maxi-mini;
		pi(ans);
		if(ans > k){
			printf("No more girlfriends!\n");
		}
		else if(ans==k){
			printf("Lucky chap!\n");
		}
		else printf("Chick magnet Jhool!\n");

	}
	return 0;
}

