#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, l, i, j, count=0;
	char temp, str[12], swaped[12];
	scanf("%d", &t);
	while(t--)
	{
		count++;
		scanf("%s", str);
		strcpy(swaped, str);
		l = strlen(str);
		for(i=0;i<l;i++)
		{
			for(j=i+1;j<l;j++)
			{
				swap(str[i], str[j]);
				if(strcmp(str, swaped) < 0 && str[0] != '0')
					strcpy(swaped, str);
				swap(str[i], str[j]);
			}
		}
		printf("Case #%d: %s", count, swaped);
		strcpy(swaped, str);
		for(i=0;i<l;i++)
		{
			for(j=i+1;j<l;j++)
			{
				swap(str[i], str[j]);
				if(strcmp(str, swaped) > 0)
					strcpy(swaped, str);
				swap(str[i], str[j]);
			}
		}
		printf(" %s\n", swaped);
	}
	return 0;
}

