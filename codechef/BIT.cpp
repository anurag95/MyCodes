#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define sortv(a) sort(a.begin(),a.end())
#define DRT() int t; cin>>t; while(t--)
#define DRI(n) int n; cin>>n;
#define DRII(n,m) int n,m; cin>>n>>m; 
using namespace std;
int n;
int freqto(int arr[], int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=arr[index];
		index -= (index&-index);
	}
	return sum;
}
void update(int arr[], int index, int value)
{
	while(index<=n)
	{
		arr[index]+=value;
		index += (index&-index);
	}
}
int freqat(int arr[], int index)
{
	int sum = arr[index];
	if(index>0)
	{
		int z = index - (index&-index);
		int y = index-1;
		while(y!=z)
		{
			sum -= arr[index];
			y -= (y&-y);
		}
	}
	return sum;
}
void create(int arr[], int index)
{
	int sum = arr[index]; 
	int z = index - (index&-index);
	int y = index - 1;
	while(y!=z)
	{
		sum+= arr[y];
		y -= (y&-y);
	}
	arr[index] = sum;
}
int main()
{
	int arr[10010], i;
	scanf("%d", &n);
	scanf("%d", &arr[1]);
	for(i=2;i<=n;i++)
	{
		scanf("%d", &arr[i]);
		create(arr, i);
		printf("\n%d ", arr[i]);
	}
	for(i=1;i<=n;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
