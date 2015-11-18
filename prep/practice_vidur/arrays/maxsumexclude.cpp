#include <iostream>
#include <algorithm>
using namespace std;
/// or spoj FARIDA
/// max sum subarray with consecutive not allowed
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	int inc = arr[0], exc = 0;
	for (int i = 1; i < n; ++i)
	{
		int temp = max(inc, exc);
		inc = (exc + arr[i]);
		exc = temp;
	}
	cout<<max(inc,exc)<<endl;
	return 0;
}