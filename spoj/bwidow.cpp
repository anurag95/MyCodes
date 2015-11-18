#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, i, arr[1010][2];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int ind, max = INT_MIN;
		for(i=0;i<n;i++)
		{
			scanf("%d%d", &arr[i][0], &arr[i][1]);
			if(arr[i][0]>max)
				max = arr[i][0];
		}
		for(i=0;i<n;i++)
		{
			if(max!=arr[i][0])
			{
				if(max<=arr[i][1])
					break;
			}
			else ind = i; 
		}
		if(i == n)
		{
			printf("%d\n", ind+1);
		}
		else   printf("-1\n");
	}
	return 0;
}

