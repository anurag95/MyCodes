#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int edit_dist(char *s1, char *s2){
	int m = strlen(s1), n = strlen(s2);
	int dp[m+1][n+1];
	for (int i = 0; i <= m; ++i)
		dp[i][0] = i;
	
	for (int j = 0; j <= n; ++j)
		dp[0][j] = j;

	for (int i = 1; i <= m; ++i){
		for (int j = 1; j <= n; ++j){
			int ins = dp[i-1][j];
			int del = dp[i][j-1];
			int rep = dp[i-1][j-1];
			ins += 1;
			del += 1;
			rep += (s1[i-1] != s2[j-1]);
			dp[i][j] = min( min(ins, del), rep);
		}
	}
	return dp[m][n];
}

int main(){
	char s1[100], s2[100];
	cin>>s1>>s2;
	cout<<edit_dist(s1, s2)<<endl;
	return 0;
}