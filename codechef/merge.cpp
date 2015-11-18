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

ll inve=0;
void merge(int arr[], int left,int right);
void mergeSort(int arr[], int l, int r)
{
	int mid=(l+r)/2;
	if (r > l)
	{

		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);

		merge(arr, l, r);
	}
}

void merge(int arr[], int left, int right)
{
	int k=0, i, j;
	int mid=((left+right)/2) + 1;
	int temp[100010];
	i=left;
	j=mid;
	while ((i <= mid-1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inve = inve + (ll)(mid - i);
		}
	}
	while (i <= mid-1)
		temp[k++] = arr[i++];


	while (j <= right)
		temp[k++] = arr[j++];

	for (i=left,k=0; i <= right; i++,k++)
	{
//		printf("%d ", temp[k]);
		arr[i] = temp[k];
	}
//	printf("\n");
}



int main()
{
	int var=0, i, j, t, n;
	ll k;
	si(t)
	while(t--)
	{
		inve=0;
		int flag = 0;
		var++;
		si(n);
		scanf("%lld", &k);
		int repeat[100010] = {0};
		int arr[100010];
		for(i=0;i<n;i++)
		{
			si(arr[i])
			repeat[arr[i]]++;
			if(repeat[arr[i]] > 1)
				flag = 1;
		}
		mergeSort(arr, 0,n-1);
//		pll(inve)
		if(k > inve)
		{
			if(flag)
				printf("Case %d: 0\n", var);
			else 
				printf("Case %d: %lld\n", var, (k-inve)&1);
		}
		else printf("Case %d: %lld\n", var, inve - k);
	}
	return 0;
}

