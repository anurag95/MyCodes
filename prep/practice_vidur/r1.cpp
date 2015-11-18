#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n], ans[n];
	for (int i = 0; i < n; ++i)
	{	
		cin>>a[i];
		ans[i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		if(a[i] > a[i-1])
		{
			//ans[i] += 1;
			ans[i] = ans[i-1] + 1;
			//cout<<"HOODI "<<i<<" ";
		}
	}
	//cout<<endl;
	for (int i = n-2; i >= 0; --i)
	{
		if(a[i] > a[i+1])
		{
			ans[i] = max(ans[i],ans[i+1] + 1);
			//cout<<"BAABA "<<i<<" ";
		}
	}
	//cout<<endl;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += ans[i];
		//cout<<ans[i]<<" ";
	}
	//cout<<endl;
	cout<<sum<<endl;
}