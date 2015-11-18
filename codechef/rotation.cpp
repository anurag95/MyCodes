#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, d, arr[100010], i, index;
	char c;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	i = 1;
	index = 1;
	while(m--)
	{
		getchar();
		scanf("%c", &c);
		scanf("%d", &d);
		if(c == 'C')
			index = (index-d+n)%n;
		else if(c == 'A')
			index = (index+d)%n;
		else {
			d = d-(index-i);
			d = (d+n)%n;
			if(d == 0)
				d = n;
			printf("%d\n", arr[d]);
		}
	}
	return 0;
}




