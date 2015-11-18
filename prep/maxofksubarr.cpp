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
void findmaxofkwindow(int arr[], int n, int k)
{
	deque<int> Q;
	int i;
	for(i=0;i<k;i++)
	{
		while(!Q.empty() && arr[i]>=arr[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	for(;i<n;i++)
	{
		printf("%d ", arr[Q.front()]);
		while(!Q.empty() && Q.front() <= i-k)
			Q.pop_front();
		while(!Q.empty() && arr[i]>=arr[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	printf("%d\n", arr[Q.front()]);
	return ;
}
int main()
{
	int arr[] = {12, 1, 78, 90, 57, 89, 56};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	findmaxofkwindow(arr, n, k);

	return 0;
}

