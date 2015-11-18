#include <iostream>
using namespace std;

int main()
{
	int r, c;
	cin>>r>>c;
	int mat[r][c];
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin>>mat[i][j];

	int k = 0, l = 0;
	while(k < r && l < c)
	{
		for (int i = l; i < c; ++i)
		{
			cout<<mat[k][i]<<" ";
		}
		k++;

		for (int i = k; i < r; ++i)
		{
			cout<<mat[i][c-1]<<" ";
		}
		c--;

		if(k < r)
		{
			for (int i = c-1; i >= l; --i)
			{
				cout<<mat[r-1][i]<<" ";
			}
			r--;
		}

		if(l < c)
		{
			for (int i = r-1; i >= k; --i)
			{
				cout<<mat[i][l]<<" ";
			}
			l++;
		}
	}
	cout<<endl;
	return 0;
}