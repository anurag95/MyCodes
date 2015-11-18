#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int a[n], b[n], loc[n];
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
		for(i=0;i<n;i++)
			scanf("%d", &b[i]);
		for(i=0;i<n;i++)
			loc[b[i]] = i;
		for(i=0;i<n;i++)
			b[i] = loc[a[i]];
		printf("%d\n", lis(a));
	}
	return 0;
}
