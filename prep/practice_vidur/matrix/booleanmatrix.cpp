#include <iostream>
using namespace std;

bool mat[100][100];
int r, c;

void changemat()
{
	bool row = 0, col = 0;
	for (int j = 0; j < c; ++j)
	{
		if(mat[0][j])
		{
			row = true;
			break;
		}
	}

	for (int i = 0; i < r; ++i)
	{
		if (mat[i][0])
		{
			col = true;
			break;
		}
	}

	for (int i = 1; i < r; ++i)
		for (int j = 1; j < c; ++j)
			if(mat[i][j])
				mat[0][j] = mat[i][0] = true;

	for (int i = 1; i < r; ++i)
		for (int j = 1; j < c; ++j)
			mat[i][j] = mat[0][j] || mat[i][0];

	if(row)
		for (int j = 0; j < c; ++j)
			mat[0][j] = true;

	if(col)
		for (int i = 0; i < r; ++i)
			mat[i][0] = true;
	
}

int main()
{
	cin>>r>>c;
	for (int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			cin>>mat[i][j];
	changemat();
	cout<<"Changed matrix"<<endl;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}