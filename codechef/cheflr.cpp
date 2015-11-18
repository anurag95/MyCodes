#include<bits/stdc++.h>
#define max 1000000007
#define ll long long int
using namespace std;
int main()
{
	int t, i, level, num;
	char ch[100101];
	scanf("%d", &t);
	while(t--)
	{
		level = 0;
		num = 1;
		scanf("%s", ch);
		int l = strlen(ch);
		for(i=0;i<l;i++)
		{
			if(level%2 == 0)
			{
				if(ch[i] == 'l') num = (num*2)%max;
				else num = ((num*2)+2)%max;
			}
			else {
				if(ch[i] == 'l') num = ((num*2)-1)%max;
				else num = ((num*2)+1)%max;
			}
			level++;
		}
		printf("%d\n", num);
	}
	return 0;
}
