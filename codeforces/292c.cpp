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
	int n, i;
	int flag[11] = {0};
	char arr[20];
	si(n)
	scanf("%s", arr);
	for(i=0;arr[i];i++)
	{
		arr[i]-='0';
		if(arr[i] == 4)
		{
			flag[2]+=2;
			flag[3]++;
		}
		else if(arr[i] == 6)
		{
			flag[5]++;
			flag[3]++;
		}
		else if(arr[i] == 8)
		{
			flag[7]++;
			flag[2]+=3;
		}
		else if(arr[i] == 9)
		{
			flag[7]++;
			flag[2]++;
			flag[3]+=2;
		}
		else flag[arr[i]]++;
	}
	for(i=9;i>=2;i--)
	{
		while(flag[i]--)
			printf("%d", i);
	}
	printf("\n");
	return 0;
}

