#include<bits/stdc++.h>
using namespace std;
int construct(int arr[], int s, int e, int *st, int i)
{
	if(s==e)
		st[i] = arr[s];
	else {
	int mid = (s+e)/2;
	st[i] = construct(arr, s, mid, st, 2*i+1) + construct(arr, mid+1, e, st, 2*i+2);
	}
	return st[i];
}
int main()
{
	int t, n, arr[1000], i, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int x = (int)(ceil(log2(n)));
		int size = 2*(int)pow(2, x) - 1;
		int *st = new int[size];
		for(i=0;i<n;i++)
			scanf("%d", &arr[i]);
		construct(arr, 0, n-1, st, 0);
		for(i=0;i<size;i++)
			printf("%d ", st[i]);
		printf("\n");
	}
	return 0;
}


