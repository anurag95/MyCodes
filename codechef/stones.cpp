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
int main()
{
	int arr[6], i;
	for(i=0;i<6;i++)
		si(arr[i])
	int myxor = 0;
	for(i=0;i<6;i++)
	{
		myxor = myxor^(arr[i%6]+arr[(i+1)%6]+arr[(i+2)%6]);
	}
	if(myxor >0)
		printf("Winning\n");
	else printf("Losing\n");
	return 0;
}

