#include <iostream>
#include <algorithm>
using namespace std;

int maxksubarray(int *arr, int n, int k)
{
	int lsum[n];
	lsum[0] = arr[0];
	for (int i = 1; i < n; ++i)
		lsum[i] = lsum[i-1] + arr[i];
	int rsum[n];
	rsum[n-1] = arr[n-1];
	for (int i = n-2; i >= 0; --i)
		rsum[i] = rsum[i+1] + arr[i];
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		if(i >= k && i < n - k)
		{
			if((lsum[i-1]-lsum[i-1-k]) + (rsum[i]-rsum[i+k]) > mx))
				mx = (lsum[i-1]-lsum[i-1-k]) + (rsum[i]-rsum[i+k]);
		}
	}
	return mx;
}

int main()
{
	int n, k;
	cin>>n>>k;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	cout<<maxksubarray(arr, n, k)<<endl;
}