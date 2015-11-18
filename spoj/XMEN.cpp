#include<bits/stdc++.h>
int main()
{
	int t=1, a[1000], b[1000], n, i, j;
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
			a[i] = loc[a[i]];
		int k = 0, mid, l, r;
		b[0] = a[0];
		for(i=1;i<n;i++)
		{
			if(a[i] > b[k])
				b[++k] = a[i];
			else {
				l = 0;
				r = k;
				while(l<=r)
				{
					mid = (r+l)/2;
					if(a[i] > b[mid])
						l = mid+1;
					else    r = mid-1;
				}
				b[l] = a[i];
			}
		}
		printf("%d\n", k+1);
	}
	return 0;
}

