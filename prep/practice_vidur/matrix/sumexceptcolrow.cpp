#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int a[n][m];
	int rsum[n];
	int csum[m];
	int sum = 0;
	fill(rsum, rsum+n, 0);
	fill(csum, csum+m, 0);
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			sum += a[i][j];
			rsum[i] += a[i][j];
			csum[j] += a[i][j];
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int i, j;
		cin>>i>>j;
		cout<<sum-rsum[i]-csum[j]+a[i][j]<<endl;
	}
	return 0;
}