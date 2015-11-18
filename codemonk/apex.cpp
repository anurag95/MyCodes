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
#define f first
#define s second
int main()
{
	int i, j, t, m, n, u, v, g, h;
	pair<int, int> newsub[100010], oldsub[100010];
	si(t)
	while(t--)
	{
		sii(m, n);
		for(i=0;i<m;i++)
		{
			sii(u, v);
			newsub[i] = make_pair(u, v);
		}
		for(i=0;i<n;i++)
		{
			sii(u, v);
			oldsub[i] = make_pair(u, v);
		}
		sii(g, h)
		sort(newsub, newsub+m);
		sort(oldsub, oldsub+n);
		i=0;j=0;
		while(i<m && j<n)
		{
			if(oldsub[i].f == newsub[j].f){
				g--;
				if(oldsub[i].s == newsub[j].s)
					h--;
				i++; j++;
			}
			else if(oldsub[i].f < newsub[j].f)
				i++;
			else if(oldsub[i].f > newsub[j].f)
				j++;
		}
		if(g<=0 && h<=0)
			printf("Great\n");
		else if(g<=0)
			printf("Good\n");
		else
			printf(":(\n");
	}
	return 0;
}

