#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, i, arr[27], rep[28];
	char abc[28], str[105];
	scanf("%d", &t);
	while(t--)
	{
		for(i=0;i<26;i++)
		{
			arr[i] = 0;
			rep[i] = 0;
		}
		scanf("%s", abc);
		int l = strlen(abc);
		for(i=0;i<l;i++)
			arr[abc[i]-97] = 1;
		scanf("%s", str);
		l = strlen(str);
		for(i=0;i<l;i++)
		{
			if(arr[str[i]-97] == 1)
				rep[str[i]-97] = 1;
		}
		int count=0;
		for(i=0;i<26;i++)
			if(rep[i] == 1)
				count++;
		printf("%d\n", count);
	}
	return 0;
}
