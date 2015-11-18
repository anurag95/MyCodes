#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k=0, arr[100010][3];
	while(1)
	{
		scanf("%d", &n);
		k++;
		if(n == 0)
			break;
		int i;
		for(i=0;i<n;i++)
			scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
		arr[1][0] += arr[0][1];
		int mine;
		mine = min(arr[0][1], arr[1][0]);
		arr[1][1] += min(arr[0][1]+arr[0][2], mine);
		mine = min(arr[0][1], arr[0][2]+arr[0][1]);
		mine = min(mine, arr[1][1]);
		arr[1][2] += mine;
		for(i=2;i<n;i++)
		{
			arr[i][0] += min(arr[i-1][1], arr[i-1][0]);
			int mini = min(arr[i-1][1], arr[i-1][0]);
			mini = min(mini, arr[i-1][2]);
			arr[i][1] += min(mini, arr[i][0]);
			mini = min(arr[i-1][1], arr[i-1][2]);
			arr[i][2] += min(arr[i][1], mini);
		}
		printf("%d. %d\n", k, arr[n-1][1]);
	}
	return 0;
}
