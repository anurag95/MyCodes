#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=1024, i;
	char str[1000];
	while(t--)
	{
		scanf("%s", str);
		int l = strlen(str), carry=0;
		if(l == 1 && str[0] == '1')
		{
			printf("1\n");
			continue;
		}
		for(i=l-1;i>=0;i--)
		{
			int temp = carry;
			carry = ((str[i]-48)*2 + carry)/10;
			str[i] = ((str[i]-48)*2 + temp)%10 + 48;
		}
		if(str[l-1]-48 >= 2)
		{
			str[l-1] = str[l-1]-2;
		} 
		else {
			str[l-1] = str[l-1]+8;
			i=l-2;
			while(i>=0 && str[i]-48 < 1)
			{
				str[i] = '9';
				i--;
				
			}
			if(i>=0)
			{
				str[i] -= 1;
			}
			else if(carry > 0)
				carry--;
		}
		int flag=0;
		if(carry>0)
		{
			printf("%d", carry);
			flag=1;
		}
		for(i=0;i<l;i++)
		{
			if(flag==1)
				printf("%c", str[i]);
			else if(str[i] > 48)
			{
				flag++;
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
