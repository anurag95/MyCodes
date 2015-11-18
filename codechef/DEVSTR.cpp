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
	int var, t, n, k, i, j, count, ans;
	int arr[100010], arr2[100010];
	char str[100010];
	si(t)
	while(t--)
	{
		ans = 0;
		sii(n, k);
		scanf("%s", str);
		for(i=0;i<n;i++){
			arr[i] = str[i]-48;
		}
		if(k == 1){
			var = 0;
			int ans2 = 0;
			for(i=0;i<n;i++)
			{
				if(arr[i] != var) ans2++;
				var = (var+1)%2;
			}
			var = 1;
			for(i=0;i<n;i++)
			{
				if(arr[i] != var) ans++;
				var = (var+1)%2;
			}
			if(ans < ans2){
				var = 1;
				printf("%d\n", ans);
				for(i=0;i<n;i++){
					printf("%d", var);
					var^=1;
				}
				printf("\n");
			}
			else {
				var = 0;
				printf("%d\n", ans2);
				for(i=0;i<n;i++){
					printf("%d", var);
					var^=1;
				}
				printf("\n");
			}
			continue;
		}
		i = 0; ans = 0; 
		int start = 0;
		var = 0;  // the character in consideration (0 or 1)
		while(i<n)
		{
			count = 0; // count of successive chars occuring
			j = i;
			while(j<n && arr[j] == var)
			{
				j++;
				count++;
			}
			if(count > k)
			{
				start = i;
				i = i+k;
				while(i<n && i < j-1){
					arr[i] = arr[i]^1;
					i += (k+1);
					ans++;
				}
				if(i<n && i == j-1){
					arr[i-1] = arr[i-1]^1;
					ans++;
				}
				i = j;
/*				if(count >= 2*k+1){
					arr[i+k] = (arr[i+k]+1)%2;
					i = i+k;
				}
				else {
					arr[i+k-1] = (arr[i+k-1]+1)%2;
					i = i+k-1;
				}
				ans++; */
			}
			else i = j;
			var = (var+1)%2;
		}
		printf("%d\n", ans);
		for(i=0;i<n;i++)
			printf("%d", arr[i]);
		printf("\n");
	}
	return 0;
}

