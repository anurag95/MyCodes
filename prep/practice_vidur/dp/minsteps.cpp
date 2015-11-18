#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int dp[n+1];
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i){
		dp[i] = dp[i-2] + 1;
		if(i%3 == 0){
			dp[i] = min(dp[i/3]+1,dp[i]);
		}
	}
	cout<<dp[n]<<endl;
}