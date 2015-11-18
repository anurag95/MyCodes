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
int n, arr[22][3], alex[3], sum[3];
int recur(int food)
{
	if(food == n)
		return 0;
	int i, flag=0;
	for(i=0;i<3;i++)
	{
		sum[i]+=arr[food][i];
		if(sum[i] > alex[i])
			flag=1;
	}
	if(flag)
	{
		for(i=0;i<3;i++) sum[i]-=arr[food][i];
		if(recur(food+1)) return 1;
	}
	else {
		if((sum[0]==alex[0]) && (sum[1]==alex[1]) && (sum[2]==alex[2]))
			return 1;
		else if(recur(food+1))
			return 1;
		else {
			for(i=0;i<3;i++)  sum[i]-=arr[food][i];
			return recur(food+1);
		}
	}
	return 0;
}
int main()
{
	int t, i, count=0;
	scanf("%d", &t);
	while(t--)
	{
		count++;
		scanf("%d%d%d", &alex[0], &alex[1], &alex[2]);
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
		sum[0] = sum[1] = sum[2] = 0;
		if(recur(0)) printf("Case #%d: yes\n", count);
		else printf("Case #%d: no\n", count);
	}
	return 0;
}

