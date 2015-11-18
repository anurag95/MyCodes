#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	int r;
	while(b!=0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int t, n, arr[100010], i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%d", &arr[i]);
		}
		int flag=0;
		for(i=0;i<n-1;i++)
		{
			if(gcd(arr[i], arr[i+1]) == 1)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("%d\n", n);
		else    printf("-1\n");
	}
	return 0;
}
