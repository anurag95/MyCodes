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
	int i, j, k, map[3], colour[6];
	char str[10];
	si(t)
	while(t--)
	{
		for(i=0;i<6;i++){
			scanf("%s", str);
			if(strcmp(str, "blue") == 0) colour[i] = 1;
			else if(strcmp(str, "yellow") == 0) colour[i] = 2;
			else if(strcmp(str, "green") == 0) colour[i] = 3;
			else if(strcmp(str, "orange") == 0) colour[i] = 4;
			else if(strcmp(str, "black") == 0) colour[i] = 5;
			else if(strcmp(str, "red") == 0) colour[i] = 6;
		}
		int flag = 0;
		for(i=0;i<6;i++)
		{
			map[0] = map[2] = map[1] = 0;
			map[i/2] = 1;
			for(j=0;j<6;j++)
			{
				if(map[j/2] == 1)
					continue;
				map[j/2] = 1;
				for(k=0;k<6;k++)
				{
					if(map[k/2] == 1)
						continue;
					map[k/2] = 1;
					if(colour[i] == colour[j] && colour[i] == colour[k])
						flag = 1;
					map[k/2] = 0;
				}
				map[j/2] = 0;
			}
			map[i/2] = 0;
		}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

