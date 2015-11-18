#include<bits/stdc++.h>
int main()
{
	int t, count=0;
	scanf("%d", &t);
	while(t--)
	{
		count++;
		int var, k, i, j, table[502]={0};// arr[501][501]={0};
		scanf("%d", &k);
		int flag=0;
		for(i=1;i<=k;i++)
		{
			if(table[i] != 0)
			{
				scanf("%d", &var);
				while(var--)
				{
					scanf("%d", &j);
					if(table[j] == table[i])
					{
						flag=1;
						break;
					}
					else if(table[j] == 0)
						table[j] = (table[i]%2)+1;
				}
				if(flag)
					break;
			}
			else {
				int one=0, two=0, temp[502], num, ind=0;
				//table[i] = 1;
				scanf("%d", &var);
				num=var;
				while(var--)
				{
					scanf("%d", &j);
					temp[ind++] = j;
					if(table[j] == 1)
						one=1;
					else if(table[j] == 2)
						two=2; 
				}
				if(one && two)
				{
					flag=1;
					break;
				}
				else if(one)
				{
					table[i] = 2;
					for(int g=0;g<num;g++)
					{
						table[temp[g]] = 1;
					}
				}
				else
				{
					table[i] = 1;
					for(int g=0;g<num;g++)
					{
						table[temp[g]] = 2;
					}
				}
			}
		}
		if(flag)
			printf("Case %d: 0 0 0\n", count);
		else {
			int a=0, b=0;
			for(i=1;i<=k;i++)
			{
				if(table[i] == 1)
					a++;
				else if(table[i] == 2)
					b++;
			}
			if(a>b)
				printf("Case %d: 1 %d %d\n", count, b, a);
			else
				printf("Case %d: 1 %d %d\n", count, a, b);
		}
	}
	return 0;
}
