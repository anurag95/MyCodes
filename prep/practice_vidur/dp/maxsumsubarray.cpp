#include <iostream>
#include <algorithm>
using namespace std;

int maxsum(int *arr, int n){
	int curr = arr[0], total = arr[0];
	for (int i = 1; i < n; ++i){
		curr = max(arr[i], curr + arr[i]);
		total = max(curr, total);
	}
	return total;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	cout<<maxsum(arr, n)<<endl;
	return 0;
}