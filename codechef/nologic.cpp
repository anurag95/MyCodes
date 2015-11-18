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
int main()
{
	int t;
	si(t)
	while(t--)
	{
		getchar();
		char str[500];
		int arr[150] = {0};
		scanf("%[^\n]", str);
		int l = strlen(str);
		for(int i=0;i<l;i++)
		{
			arr[str[i]]++;
			if(str[i]>64 && str[i]<91)
				arr[str[i]+32]++;
			else if(str[i]>96 && str[i]<123)
				arr[str[i]-32]++;
		}
//		for(int i=65;i<91;i++)
//			printf("%d ", arr[i]);
//		printf("\n");
		int flag = 0;
		for(int i=65;i<=90;i++)
		{
			if(arr[i] == 0)
			{
				flag = 1;
				printf("%c\n", i);
				break;
			}
		}
		if(!flag)
		{
			for(int i=97;i<=122;i++)
			{
				if(arr[i] == 0)
				{
					flag = 1;
					printf("%c\n", i);
					break;
				}

			}
		}
		if(!flag)
			printf("~\n");
	}
	return 0;
}

