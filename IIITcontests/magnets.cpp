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
	char s[62];
	scanf("%[^\n]", s);
	getchar();
	while(strcmp(s, "END")!=0)
	{
		int i, arr[130] = {0};
		int l = strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]!=' ' && arr[s[i]] == 0)
				arr[s[i]] = 1;
			else if(s[i] == ' ')
				continue;
			else break;
		}
		if(i==l)
			printf("%s\n", s);
		scanf("%[^\n]", s);
		getchar();
	}
	return 0;
}

