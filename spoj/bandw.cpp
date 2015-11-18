#include<bits/stdc++.h>
int main()
{
	int turns=0;
	char a[510], b[510];
	while(1)
	{
		turns = 0;
		scanf("%s", a);
		scanf("%s", b);
		if(a[0] == '*')
			break;
		int l = strlen(a);
		int flag = 1;
		for(int i=0;i<l;i++)
		{
			if(flag==1)
			{
				if(a[i]!=b[i])
					flag=0;
			}
			else {
				if(a[i]==b[i])
				{
					flag=1;
					turns++;
				}
			}
		}
		if(flag == 0)
			turns++;
		printf("%d\n", turns);
	}
	return 0;
}



