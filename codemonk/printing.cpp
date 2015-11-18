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
	char str[10010], res[10010];
	int arr[26], i;
	si(t)
	while(t--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%s", str);
		scanf("%s", res);
		for(i=0;res[i]!='\0';i++){
			arr[res[i]-97]++;
		}
		int j=0;
		for(i=0;str[i];i++)
		{
			while(arr[j] == 0)
				j++;
			if(j >= 26)
				break;
			if(str[i] > (char)(j+97)){
				str[i] = (char)(j+97);
				arr[j]--;
			}
		}
		printf("%s\n", str);
	}
	return 0;
}

