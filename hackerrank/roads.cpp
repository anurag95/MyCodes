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
int arr[100000][2], visited[100000],cycle=0;
double tmp[100010];

double ans = 0.0f;
void dfs(int start, int i, double prob)
{
		visited[i] = 1;

		tmp[i] = prob*((double)arr[i][1]/100);
		
		if(visited[arr[i][1]] == 1)
		{
			ans += ((prob*((double)arr[i][1]/100))/tmp[arr[i][1]]);
		}
		else
		{
			dfs(start, arr[i][0], prob*((double)arr[i][1]/100));
		}
	//	visited[i] = 0;
	
}
int main()
{
	si(n)
	memset(tmp,1,sizeof(tmp));
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i][0], &arr[i][1]);
		arr[i][0]--;
	}
	for(int i=0;i<n;i++){
		if(!visited[i])
		{	visited[i] = 1;
			dfs(i, arr[i][0], (double)arr[i][1]/100);
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}

