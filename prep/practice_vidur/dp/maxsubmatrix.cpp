#include <iostream>
#include <algorithm>
using namespace std;

bool m[100][100];
int s[100][100];

void printmaxsubmatrix(int r, int c){
	for (int i = 0; i < r; ++i)
		s[i][0] = m[i][0];
	for (int j = 0; j < c; ++j)
		s[0][j] = m[0][j];

	for (int i = 1; i < r; ++i){
		for (int j = 0; j < c; ++j){
			if(m[i][j])
				s[i][j] = min(min(s[i][j-1], s[i-1][j]), s[i-1][j-1]) + 1;
			else
				s[i][j] = 0;
		}
	}
	int mxs = 0, mxi, mxj;
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			if(mxs < s[i][j]){
				mxs = s[i][j];
				mxi = i;
				mxj = j;
			}
		}
	}
	for (int i = mxi; i > mxi - mxs; --i){
		for (int j = mxj; j > mxj - mxs; --j){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
	
int main(){
	int r, c;
	cin>>r>>c;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin>>m[i][j];
	printmaxsubmatrix(r, c);
	return 0;
}