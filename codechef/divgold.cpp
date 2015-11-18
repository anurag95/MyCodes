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
char str[53], res[53], temp[53], ch, temp2[52];
int main()
{
	int t, i, j, n, k;
	si(t)
	while(t--)
	{
		si(n);
		scanf("%s", str);
		strcpy(res, str);
		for(i=0;i<n;i++)
		{
			int c=0;
			for(k=0;k<n;k++)
			{
				if(k!=i)
					temp[c++] = str[k];
				else ch = str[k];
			}
			temp[c] = 0;
			for(j=0;j<n;j++)
			{
				c = 0;
				for(k=0;k<j;k++)
					temp2[k] = temp[c++];
				temp2[k++] = str[i];
				for(;temp[c];k++)
					temp2[k] = temp[c++];
				temp2[k] = 0;
				if(strcmp(temp2, res) < 0)
					strcpy(res, temp2);
			}
		}
		printf("%s\n", res);
	}
	return 0;
}

