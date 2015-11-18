#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, i, mouse[132000], hole[132000];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%d", &mouse[i]);
		for(i=0;i<n;i++)
			scanf("%d", &hole[i]);
		sort(mouse, mouse+n);
		sort(hole, hole+n);
		int max = INT_MIN, sub;
		for(i=0;i<n;i++)
		{
			sub = mouse[i] - hole[i];
			if(sub<0)
				sub = -sub;
			if(sub>max)
				max = sub;
		}
		printf("%d\n", max);
	}
	return 0;
}


