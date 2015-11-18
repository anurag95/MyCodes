#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define pii pair<int,int>

int main()
{
	int n;
	cin>>n;
	pii arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i].first>>arr[i].second;
	sort(arr, arr+n);
	stack < pii > s;
	s.push(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		pii top = s.top();
		if(top.second < arr[i].first)
			s.push(arr[i]);
		else if(top.second >= arr[i].first)
		{
			top.second = arr[i].second;
			s.pop();
			s.push(top);
		}
	}
	cout<<"Merged Intervals: "<<endl;
	while(!s.empty())
	{
		pii t = s.top();
		cout<<t.first<<", "<<t.second<<endl;
		s.pop();
	}
	return 0;
}
