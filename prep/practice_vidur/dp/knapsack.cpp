#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int *val, int *wei, int n, int w){
	int dp[n+1][w+1];
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 0;
	for (int j = 0; j <= w; ++j)
		dp[0][j] = 0;

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= w; ++j){
			if(wei[i-1] <= j)
				dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][ j-wei[i-1] ]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main(){
	int n, w;
	cin>>n>>w;
	int val[n], wei[n];
	for (int i = 0; i < n; ++i)
		cin>>val[i];
	for (int i = 0; i < n; ++i)
		cin>>wei[i];
	cout<<knapsack(val, wei, n, w)<<endl;
	return 0;
}