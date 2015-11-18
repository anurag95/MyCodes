#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n], mn[n+1];
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	mn[0] = a[0];
	for (int i = 1; i < n; ++i)
		mn[i] = min(mn[i-1], a[i]);
	for (int i = 0; i < n; ++i)
		cout<<mn[i]<<" ";
	cout<<endl;
	return 0;
}