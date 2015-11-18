#include <iostream>
#include <algorithm>
using namespace std;

int lis(int *arr, int n){
	int lis[n];
	for (int i = 0; i < n; ++i)
		lis[i] = 1;
	
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	int mx = lis[0];
	for (int i = 1; i < n; ++i)
		mx = max(mx, lis[i]);
	return mx;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	cout<<lis(arr, n)<<endl;
	return 0;
}