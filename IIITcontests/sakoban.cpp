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
	int r, c, k, i, j, x, y;
	char board[16][16], str[52];;
	si(r, c)
	while(r!=0)
	{
		int count=0;
		for(i=0;i<r;i++)
			scanf("%s", board[i]);
		for(i=0;i<j;i++)
		{
			for(j=0;j<0;j++)
			{
				if(arr[i][j] == 'b')
					count++;
				else if(arr[i][j] == 'w')
				{
					x = j;
					y = i;
				}
			}
		}
		scanf("%s", str);
		int l = strlen(str);
		for(k=0;k<l;k++)
		{
			switch(str[k]) {
				case 'D': if(arr[y+1][x] == '.')
							  y++;
						  else if(arr[y+1][x]=='B'||arr[y+1][x]=='b')
						  {
							  if(arr[y+2][x]=='B']||arr[y+2][x]=='b'||arr[y+2][x]=='#')
								  continue;
							  else {

							  }
			}
	return 0;
}

