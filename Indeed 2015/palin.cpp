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
bool ispalin(char str[], int s, int e)
{
	while(s<=e && (str[s] == str[e]))
	{
		s++;
		e--;
	}
	if(s>=e)
		return true;
	else return false;
}
bool ispalin2(char str[], char a[], int s, int e)
{
	int m=0;
	int flag = 0;
	while(s<=e && (str[s] == str[e]))
	{
		if(str[s] > a[m] && !flag)
			return false;
		else if(str[s]<a[m])
			flag=1;
		m++;
		s++;
		e--;
	}
	if(s>=e)
		return true;
	else return false;
}
int main()
{
	int t, m, j, i, k;
	char str[1005], abtak[1005];
	si(t)
	while(t--)
	{
		scanf("%s", str);
		int len = -1;
		int l = strlen(str);
		for(i=0;i<l;i++)
		{
			for(j=l-1;j>=i;j--)
			{
				if(len > j-i+1)
					break;
				else if(len < (j-i+1) && ispalin(str, i, j))
				{
					len = j-i+1;
					abtak[0] = '\0';
					for(k=i, m=0;k<=j;k++,m++)
						abtak[m] = str[k];
					abtak[m] = '\0';
				}	
				else if(len == (j-i+1) && ispalin2(str, abtak, i, j))
				{
					len = j-i+1;
					abtak[0] = '\0';
					for(k=i, m=0;k<=j;k++,m++)
						abtak[m] = str[k];
					abtak[m] = '\0';
				}
			}
		}
		printf("%s\n", abtak);
	}
	return 0;
}

