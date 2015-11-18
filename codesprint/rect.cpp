#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, x, y, a, b, c, d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d", &x,&y,&a,&b,&c,&d);
		int min = x-a;
		if(min<0)
			min = -min;
		int var = x-c;
		if(var<0)
			var=-var;
		if(var<min)
			min = var;
		var = y-b;
		if(var<0)
			var=-var;
		if(var<min)
			min = var;
		var = y-d;
		if(var<0)
			var=-var;
		if(var<min)
			min = var;
		printf("%d\n", min);
	}
	return 0;
}
