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

int table[200010];

void compute(int sub[], int l)
{
	int i=0, j=1;
	table[i] = -1;
	table[j] = 0;
	while(j<=l)
	{
		if(sub[i] == sub[j])
		{
			table[j+1] = table[j]+1;
			i++;
			j++;
		}
		else if(i>0)
			i = table[i];
		else {
			table[j+1] = 0;
			j++;
		}
	}
}


int main()
{
	int n, w;
	sii(n, w)
	int i, j;
	int arr[200010],diffa[200010], diffb[200010];
	for(i=0;i<n;i++)
		si(arr[i])
	for(i=1;i<n;i++)
	{
		diffa[i-1] = arr[i]-arr[i-1];
	}
	for(i=0;i<w;i++)
		si(arr[i])
	for(i=1;i<w;i++)
	{
		diffb[i-1] = arr[i]-arr[i-1];
	}
	if(w==1)
	{
		printf("%d\n", n);
		return 0;
	}
	compute(diffb, w-1);
	int m=0, count=0;
	i=0;
	while(m+i < n-1)
	{
		if(diffb[i] == diffa[m+i])
		{
			if(i == w-2)
			{
				count++;
				m = m+(i+1)-table[i+1];
				if(table[i+1] > -1)
				{
					i = table[i+1];
				}
				else {
					i=0;
				}
			}
			else
				i++;
		}
		else {
			if(table[i] > -1)
			{
				m = m+i-table[i];
				i = table[i];
			}
			else {
				i=0;
				m++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}

