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
	int i;
	char str[100010];
	scanf("%s", str);
	i=1;
	int max = INT_MIN, count = 1, ascii = INT_MAX;
	while(str[i] != '\0')
	{
		if(str[i] == str[i-1])
			count++;
		else {
			if(max < count)
			{
				max = count;
				ascii = (int)str[i-1];
			}
			else if(max == count && (int)str[i-1]<ascii)
			{
				ascii = (int)str[i-1];
			}
			count = 1;
		}
		i++;
	}
	if(max < count)
	{
		ascii = (int)str[i-1];
		max = count;
	}
	else if(max == count && (int)str[i-1]<ascii)
	{
		ascii = (int)str[i-1];
	}
	printf("%c\n%d\n", (char)ascii, max);
	return 0;
}

