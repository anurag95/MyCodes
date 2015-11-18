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
int visited[26];
char s[1010], t[1010], str[7];
vector<int> v[26];
int dfs(int cur, int end)
{
	int i=0;
	if(cur == end)
		return 1;
	for(i=0;i<v[cur].size();i++)
	{
		if(visited[v[cur][i]] == 0)
		{
			visited[v[cur][i]] = 1;
			if(dfs(v[cur][i], end))
				return 1;
		}
	}
	return 0;
}
int main()
{
	int T, i, j;
	si(T)
	while(T--)
	{
		for(i=0;i<26;i++)
			v[i].clear();
		scanf("%s", s);
		scanf("%s", t);
		int m;
		scanf("%d", &m);
		int copy = m;
		while(copy--)
		{
			scanf("%s", str);
			v[str[0]-97].pb(str[3]-97);
		}
		int l = strlen(s);
		if(l != strlen(t))
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<l;i++)
		{
			memset(visited, 0 , sizeof(visited));
			if(dfs(s[i]-97, t[i]-97) == 1)
				continue;
			else break;
		}
		if(i != l)
			printf("NO\n");
		else  printf("YES\n");
	}
	return 0;
}

