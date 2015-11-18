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
	int newsize[100010], oldsize[100010];
	si(t)
	while(t--)
	{
		vector<int> newsub[100010], oldsub[100010];
		memset(newsize, 0, sizeof(newsize));
		memset(oldsize, 0, sizeof(oldsize));
		sii(m, n);
		for(i=0;i<m;i++)
		{
			sii(u, v);
			newsub[u].insert(v);
			newsize[u]++; 
		}
		for(i=0;i<n;i++)
		{
			sii(u, v);
			oldsub[u].insert(v);
			oldsize[v]++;
		}
		sii(g, h)
		for(i=0;i<m)
		i=0;j=0;
		while(i<m && j<n)
		{
			if(oldsub[i].f == newsub[j].f){
				g--;
				if(oldsub[i].s == newsub[i].s)
					h--;
				i++; j++;
			}
			else if(oldsub[i].f < newsub[i].f)
				i++;
			else if(oldsub[i].f > newsub[i].f)
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

