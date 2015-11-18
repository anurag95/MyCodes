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
	int t;
	si(t)
	char str[100010];
	while(t--)
	{
		int arr[27] = {0};
		scanf("%s", str);
		for(int i=0;str[i]!='\0';i++)
		{
			arr[str[i]-97] = 1;
		}
		int len = 0;
		for(int i=0;i<26;i++)
			len += arr[i];
		printf("%d\n", len);
	}
	return 0;
}

