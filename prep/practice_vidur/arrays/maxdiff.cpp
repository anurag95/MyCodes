#include <iostream>
using namespace std;

int findmaxdiff(int *v, int n)
{
	int max_diff = v[1] - v[0];
	int min_ele = v[0];
	for (int i = 1; i < n; ++i)
	{
		if(v[i] - v[i-1] > max_diff)
			max_diff = v[i] - min_ele;
		if(v[i] < min_ele)
			min_ele = v[i];
	}
	return max_diff;
}

int main()
{
	int n;
	cin>>n;
	int v[n];
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	cout<<"Max difference is: "<<findmaxdiff(v, n)<<endl;
	return 0;
}