#include<bits/stdc++.h>
using namespace std;
void compute(int table[], char sub[])
{
	int i=0, j=1, l = strlen(sub);
	table[i] = -1;
	table[j] = 0;
	while(j<=l-1)
	{
		if(sub[i] == sub[j])
		{	
			table[j+1] = table[j]+1;
			i++;
			j++; 
		}
		else if(i!=0)
			i=0;
		else {
			table[j+1] = 0;
			j++;
		}
	}
	//if(sub[i] == sub[j])
	//	table[j+1] = table[j]+1;
}
int main()
{
	int t, i, n, m, l, l2;
	char str[1000];
	scanf("%d", &t);
	while(t--)
	{
	//	scanf("%d", &n);
		char sub[1000];
		int table[1000];
		scanf("%s", str);
		scanf("%s", sub);
		l = strlen(str);
		l2 = strlen(sub);
		compute(table, sub);
		//for(i=0;i<=l2;i++)
		//	printf("%d ", table[i]);
		//printf("\n");
		m=0; i=0;
		while(m+i < l)
		{
			if(sub[i] == str[m+i])
			{
				if(i == l2-1)
				{	i++;
					printf("%d\n", m);
					m = m+i-table[i];
					i = table[i];
				}
				else i++;
			}
			else {
				while(table[i] > -1)
				{
					m = m+i-table[i];
					i = table[i];
					if(sub[i] == str[m+i])
						break;
				}
				i++;	
			}
		}
		//printf("Found at %d\n", m+1);
	}
	return 0;
}
