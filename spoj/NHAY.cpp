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
		else if(i>0)
			i = table[i];
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
	int t, i, flag, n, m, l, l2, flag2;
	char s;
	while(1)
	{
		scanf("%d", &n);
		char sub[n+1];
		int table[n+2];
		scanf("%s", sub);
		getchar();
//		printf("%s", sub);
		l2 = strlen(sub);
		compute(table, sub);
		i=0;m=0;
		flag = 0;
		flag2 = 0;
		while(scanf("%c", &s) != EOF)
		{
			flag2 = 1;
			if(s == '\n')
				break;
			//printf("%c\n", s);
			if(sub[i] == s)
			{
				if(i == l2-1)
				{	
					i++;
					flag = 1;
					printf("%d\n", m);
					m = m+i-table[i];
					if(table[i]>-1)
						i = table[i];
					else    i = 0;
				}
				else i++;
			}
			else {
				if(table[i] > -1){
					while(table[i] > -1 && sub[i] != s)
					{
						m = m+i-table[i];
						i = table[i];
					}
					if(i!=0) i++;
				}
				else 
				{	m++;i=0;
				}
			}
			flag2 = 0;
		}
		if(flag2 == 0)
			break;
		if(!flag)
			printf("\n");
		//printf("Found at %d\n", m+1);
	}
	return 0;
}
