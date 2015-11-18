#include<bits/stdc++.h>
int main()
{
	int n, p, q, var, i, ans[101]={0};
	scanf("%d", &n);
	scanf("%d", &p);
	for(i=0;i<p;i++)
	{
		scanf("%d", &var);
		ans[var] = 1;
	}
	scanf("%d", &q);
	for(i=0;i<q;i++)
	{
		scanf("%d", &var);
		ans[var] = 1;
	}
	for(i=1;i<=n;i++)
	{
		if(ans[i]!=1)
			break;
	}
	if(i == n+1)
		printf("I become the guy.\n");
	else printf("Oh, my keyboard!\n");
	return 0;
}
