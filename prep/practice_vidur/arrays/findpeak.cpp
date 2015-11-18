#include <iostream>
#include <vector>
using namespace std;

int findpeak(vector<int> v)
{
	int n = v.size();
	int low = 0, high = n - 1;
	while(1)
	{
		int mid = low + (high - low)/2;
		if((mid == 0 || v[mid] >= v[mid - 1]) && (mid == n - 1 || v[mid] >= v[mid + 1]))
			return mid;
		if(mid > 0 && v[mid - 1] > v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<"Peak is at "<<findpeak(v)<<endl;
	return 0;
}