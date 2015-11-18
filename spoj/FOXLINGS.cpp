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
vector<vector<int> > graph(200010);
int visited[200010] = {0};
map<int, int> M;
set<int> S;
int main()
{
	int i, a, b, n, k;
	sii(n, k);
	for(i=0;i<k;i++)
	{
		scanf("%d%d", &a, &b);
		S.insert(a);
		M[a]++;
		S.insert(b);
		M[b]++;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	int count = 0;
	vector<int> v(S.begin(), S.end());
	int size = v.size();
	for(int j=0;j<size;j++)
	{
		if(visited[v[j]] == 1)
			continue;
		count++;
		queue<int> q;
		q.push(v[j]);
		while(!q.empty())
		{
			int ve = q.front();
			q.pop();
			visited[ve] = 1;
			for(i=0;i<M[ve];i++)
			{
				if(visited[graph[ve][i]] == 0)
				{
					visited[graph[ve][i]] = 1;
					q.push(graph[ve][i]);
				}
			}
		}
	}
	printf("%d\n", n+count-size);
	return 0;
}

