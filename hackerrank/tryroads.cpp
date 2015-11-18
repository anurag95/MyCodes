#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);

int n;
int arr[100000][2], visited[100000], incoming[100000];
double ans = 0.0f;
void dfs(int start, int i, double prob)
{
	//	printf("%lf\n",prob);
	if(start == i){
		ans += prob;
	}
	else {
		if(visited[i] == 1)
			return ;
		visited[i] = 1;
		incoming[i]--;
		dfs(start, arr[i][0], prob*arr[i][1]/100);
		visited[i] = 0;
	}
}
int main()
{
	si(n)
	memset(incoming, 0, sizeof(incoming));
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i][0], &arr[i][1]);
		arr[i][0]--;
		incoming[arr[i][0]]++;
	}
	for(int i=0;i<n;i++){
		if(!visited[i])
		{
			visited[i] = 1;
			dfs(i, arr[i][0], (double)arr[i][1]/100);
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}

