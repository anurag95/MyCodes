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
	char a[100010], b[100020];
	scanf("%s", a);
	scanf("%s", b);
	int count=0, arr[100010], m;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i] != b[i]){
			arr[count++] = i;
		}
	}
	if(count%2 != 0)
		printf("impossible\n");
	else {
		m = 0;
		for(int i=0;a[i]!='\0';i++)
		{
			if(arr[m]!=i)
				printf("%c", a[i]);
			else {
				if(m<count/2){
					int var = int(a[i])-48;
					var = var^1;
					printf("%d", var);
					m++;
				}
				else printf("%c", a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

