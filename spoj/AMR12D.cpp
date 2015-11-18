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
bool ispalin(char str[])
{
	int i, l=strlen(str);
	for(i=0;i<=l/2;i++){
		if(str[i]!=str[l-1-i])
			return false;
	}
	return true;
}
int main()
{
	int t;
	si(t)
	while(t--)
	{
		char str[12];
		scanf("%s", str);
		if(ispalin(str))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

