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
char str[100010];
int n, m, i, a, b, q;
int arr[100010][3];
void print()
{
	int i, j, sum=0;
	memset(arr, 0, sizeof(arr));
	for(j=1, i=a;i<=b;i++, j++)
	{
		for(int k=0;k<3;k++)
		{
			arr[j][(k+(str[i-1]-48))%3] = arr[j-1][k];
		}
		arr[j][(str[i-1]-48)%3] += 1;
		sum += arr[j][0];
	}
	printf("%d\n", sum);
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	while(m--)
	{
		scanf("%d%d%d", &q, &a, &b);
		if(q == 1)
		{
			str[a-1] = b+'0';
		}
		else {
			print();
		}
	}
	return 0;
}

