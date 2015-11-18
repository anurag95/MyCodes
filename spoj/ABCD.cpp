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
char arr[2][200001];
int main()
{
	int n;
	si(n)
	int i, j;
	getchar();
	for(i=0;i<2*n;i++)
		scanf("%c", &arr[0][i]);
	for(i=0;i<2*n;i+=2)
	{
		int a=-1, b=-1;
		int mask[] = {1,1,1,1};
//		printf("%c %c\n", arr[0][i], arr[0][i+1]);
		mask[arr[0][i]-65] = 0;
		mask[arr[0][i+1]-65] = 0;
		for(int k=0;k<4;k++)
		{
//			printf("%d ", mask[k]);
			if(mask[k]==1)
			{
				if(a==-1) a=k;
				else b=k;
			}
		}
//		printf("\n");
		if(arr[1][i-1] == 65+a)
		{
			arr[1][i] = 65+b;
			arr[1][i+1] = 65+a;
		}
		else
		{
			arr[1][i] = 65+a;
			arr[1][i+1] = 65+b;
		}
	}
	cout<<arr[1]<<endl;
	return 0;
}

