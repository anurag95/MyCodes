#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
priority_queue< pair<int,int> > q;
int main()
{
	int n, k, i, var;
	scanf("%d%d", &n, &k);
	for(i=0;i<n;i++)
	{	
		scanf("%d", &var);
		q.push(make_pair(-var, -i));
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d %d\n", q.top().first, q.top().second);
		q.pop();
	}*/
	int count=1;
	pair<int,int> f = q.top();
	q.pop();
	while(!q.empty())
	{
		if(q.top().first == f.first && q.top().second > f.second-k)
			q.pop();
		else {
			f = q.top();
			count++;
			q.pop();
		}
	}
	printf("%d\n", count);	
	return 0;
}

