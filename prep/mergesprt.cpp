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
int glob = 0;
void merge(int arr[], int start, int mid, int end)
{
	int i = start, j = mid+1;
	int p[end-start+1], k=0;
	while(i <= mid && j <= end)
	{
		if(arr[i] <= arr[j])
			p[k++] = arr[i++];
		else {
			glob += (mid-i+1);
			p[k++] = arr[j++];
		}
	}
	while(i <= mid)
		p[k++] = arr[i++];
	while(j <= end)
		p[k++] = arr[j++];
	for(int m=0, i = start; i<=end;i++, m++)
		arr[i] = p[m];
}
void mergesort(int arr[], int start, int end)
{
	if(start >= end)
		return ;
	int mid = start + (end-start)/2;
	mergesort(arr, start, mid);
	mergesort(arr, mid+1, end);
	merge(arr, start, mid, end);

}

int main()
{
	int n, arr[1000];
	si(n)
	for(int i=0;i<n;i++)
		si(arr[i])
	mergesort(arr, 0, n-1);
	for(int i=0;i<n;i++)
		pi(arr[i])
	return 0;
}

