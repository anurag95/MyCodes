#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define sll(x) scanf("%lld", &x);

ll n, k, sans[22];
ll req, arr[22];

bool calc(ll sum, ll i)
{
	if(sum+arr[i] == req)
	{
		sans[i] = 1;
		return true;
	}
	else if(sum+arr[i] > req)
		return false;
	sum += arr[i];
	for(ll j=i+1;j<n;j++)
	{
		if(sans[j] == 0 && calc(sum, j))
		{
			sans[i] = 1;
			return true;
		}
	}
	return false;
}

int main()
{
	ll t, su, i;
	sll(t)
	while(t--)
	{
		for(i=0;i<22;i++)
			sans[i] = 0;
		su=0;
		scanf("%lld%lld", &n, &k);
		for(i=0;i<n;i++)
		{
			scanf("%lld", &arr[i]);
			su += arr[i];
		}
		if(su%k != 0 || k>n)
			printf("no\n");
		else if(k == 1)
			printf("yes\n");
		else {
			for(i=0;i<n;i++)
				if(arr[i]==0)
					sans[i]=1;
			int flag=0;
			req = su/k;
			for(i=0;i<n;i++)
			{
				if(sans[i]==0 && !calc(0, i))
				{
					printf("no\n");
					flag=1;
					break;
				}
			}
			if(!flag)
				printf("yes\n");
		}
	}
	return 0;
}
