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
struct node {
	int value;
	int index;
}
bool cmp(const node& a, const node& b)
{
	return a.value<b.value;
}
int main()
{
	int i, n, occur[2001]={0};
	node arr[2001];
	si(n)
	int flag=0;
	int ind[3];
	for(i=0;i<n;i++)
	{
		si(arr[i].value)
		arr[i].index = i;
	}
	sort(arr, arr+n, cmp);
	for(i=0;i<n;i++)
	{
		occur[arr[i].value]++;
		if(occur[arr[i].value] == 3)
		{
			flag = 3000;
			ind[0] = i;
		}
		else if(occur[arr[i]v.value] == 2)
		{
			flag++;
			if(flag<3)
				ind[flag] = i;
		}
	}

	int j;
	if(flag == 3000)
	{
		printf("YES\n");
		for(j=0;j<3;j++)
		{
			for(i=0;i<n;i++)
			{
				if(i == ind[0]-2)
				{
					if(j==0)
					{
						printf("%d ", arr[i].index);
						printf("%d ", arr[i+1].index);
						printf("%d ", arr[i+2].index);
					}
					else if(j == 1)
					{
						printf("%d ", arr[i].index);
						printf("%d ", arr[i+2].index);
						printf("%d ", arr[i+1].index);
					}
					else if(j == 2)
					{
						printf("%d ", arr[i+1].index);
						printf("%d ", arr[i].index);
						printf("%d ", arr[i+2].index);
					}
					i+=2;
				}
				else printf("%d ", arr[i].index);
			}
			printf("\n");
		}
	}
	else if(flag == 2)


	return 0;
}

