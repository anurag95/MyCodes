#include<bits/stdc++.h>
using namespace std;
int func(int )
int main()
{
	int t, m, n, i, j;
	char arr[51][51];
	scanf("%d", &t);
	while(t--)
	{
		int lasers = 0;
		scanf("%d%d", &m, &n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				scanf("%c", &arr[i][j]);
				if(arr[i][j] == 'L')
					lasers++;
			}
		int counter = 0;
		while(counter<=(1<<lasers-1))
		{
			rec()

