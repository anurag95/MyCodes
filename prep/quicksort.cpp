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
void quicksort(int arr[], int low, int high)
{
	int pivot = low, temp;
	if(first >= last)
		return ;
	int i=low+1, j = high;
	while(i<j)
	{
		while(i<last && arr[i]<=arr[pivot]) i++;
		while(arr[j]>arr[pivot]) j--;
		if(i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;
	quick(arr, low, j-1);
	quick(arr, j+1, high);
}
int main()
{
	int t;
	si(t)
	while(t--)
	{

	}
	return 0;
}

