#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	stack < int > s;
	s.push(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		int next = arr[i];

		if(!s.empty())
		{
			int element = s.top();
			s.pop();
			while(element < next)
			{
				cout<<element<<" ----> "<<next<<endl;
				if(s.empty())
					break;
				element = s.top();
				s.pop();
			}

			if(element > next)
				s.push(element);
		}
		s.push(next);
	}
	while(!s.empty())
	{
		int element = s.top();
		s.pop();
		cout<<element<<" ----> -1"<<endl;
	}
	return 0;
}