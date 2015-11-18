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
struct node {
	int h;
	int x;
	int prev;
}arr[100010];
int main()
{
	int n, i;
	si(n)
	for(i=0;i<n;i++){
		scanf("%d%d", &arr[i].x, &arr[i].h);
		arr[i].prev = (i==0)?INT_MIN:arr[i-1].x;
	}
	if(n == 1)
		printf("1\n");
	else {
		int count = 2;
		for(i=1;i<n-1;i++)
		{
			if((arr[i].x-arr[i].h) > arr[i].prev)
				count++;
			else if(arr[i].x+arr[i].h < arr[i+1].x){
				count++;
				arr[i+1].prev = arr[i].x+arr[i].h;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

