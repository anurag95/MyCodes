#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p, q, l, r, j, k, flag=0;
	int arrp[51][2], arrq[51][2], ans[1010]={0};
	scanf("%d%d%d%d", &p, &q, &l, &r);
	for(int i=0;i<p;i++)
		scanf("%d%d", &arrp[i][0], &arrp[i][1]);
	for(int i=0;i<q;i++)
		scanf("%d%d", &arrq[i][0], &arrq[i][1]);
	for(j=0;j<q;j++)
	{
		for(k=0;k<p;k++)
		{
			for(int i=l;i<=r;i++)
			{
				if(ans[i] == 1)
					continue;
				if(arrq[j][0]+i > arrp[k][1] || arrq[j][1]+i < arrp[k][0])
					continue;
				else {
					ans[i] = 1;
					continue;
				}
			}
		}
	}
	int count=0;
	for(int i=l;i<=r;i++)
		if(ans[i] == 1)
			count++;
	printf("%d\n", count);
	return 0;
}

