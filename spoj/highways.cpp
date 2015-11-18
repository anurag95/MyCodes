#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
struct Order
{
	bool operator()(P const& a, P const& b) const
	{
		return (a.second > b.second) || (a.second == b.second && a.first < b.first);
	}
};
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int i, v, e, start, end;
		scanf("%d%d%d%d", &v, &e, &start, &end);
		vector<pair<int,int> > vec[v+1];
		pair<int,int> p;
		
		vector<int> locked(v+1, 0);
		vector<int> ans(v+1, INT_MAX);
		
		int a, b, w;
		for(i=0;i<e;i++)
		{
			scanf("%d%d%d", &a, &b, &w);
			p.first = b; 
			p.second = w;
			vec[a].pb(p);
			p.first = a;
			vec[b].pb(p);
		}
		priority_queue<P, vector<P>, Order> q;
		p.first = start;
		p.second = 0;
		q.push(p);
		ans[start] = 0;
		while(!q.empty())
		{

			if(locked[(q.top()).first] == 1)
			{
				q.pop();
				continue;
			}
			locked[(q.top()).first] = 1;
			ans[(q.top()).first] = (q.top()).second;
			int var = (q.top()).first;
			int var2 = (q.top()).second;
			q.pop();
			for(i=0;i<vec[var].size();i++)
			{
				if(locked[vec[var][i].first] == 1)
					continue;
				if(ans[vec[var][i].first] > var2+vec[var][i].second)
				{
					ans[vec[var][i].first] = var2+vec[var][i].second;
					p.first = vec[var][i].first;
					p.second = ans[vec[var][i].first];
					q.push(p);
				}
			}
		}
		if(ans[end] == INT_MAX)
			printf("NONE\n");
		else    printf("%d\n", ans[end]);
	}
	return 0;
}
