#include<bits/stdc++.h>
using namespace std;
struct diff
{
	int a;
	int d;
};
bool cmp(const diff &a,const diff &b)
{
	if(a.a!=b.a)
		return a.a<b.a;
	else
		return a.d<b.d;
}
int main()
{
	int i, j, n, arr[100100], k, end=0;
	diff node[300];

	scanf("%d%d", &n, &k);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(i=0;i<k+1;i++)
	{
		for(j=i+1;j<k+2;j++)
		{
			if((arr[j]-arr[i])%(j-i)==0)
			{
				node[end].d=(arr[j]-arr[i])/(j-i);
				node[end].a=arr[i]-(node[end].d*i);
				end++;
			}
		}
	}

	sort(node,node+end,cmp);

	for(i=0;i<end;i++)
	{
		int miss=0;
		for(j=0;j<n;j++)
		{
			if(arr[j]!=(node[i].a+j*node[i].d))
				miss++;
		}
		if(miss<=k)
		{
			for(j=0;j<n-1;j++)
				printf("%d ",node[i].a+j*node[i].d);
			printf("%d\n", node[i].a+j*node[i].d);
			break;
		}
	}
	return 0;
}
