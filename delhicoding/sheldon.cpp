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
pair<int, int> arr[1005];
int mat[1003][1003];

struct comp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.s > b.s;
	}
};

int main()
{
	memset(mat, 0, sizeof(mat));
	int n, j, x, y, a, b, i=0;
	scanf("%d%d%d", &n, &x, &y);
	arr[i++] = make_pair(0, 0);
	arr[i++] = make_pair(x, y);
	for(;i<n+2;i++)
	{
		scanf("%d%d", &a, &b);
		arr[i] = make_pair(a, b);
	}
	for(i=0;i<n+2;i++)
	{
		for(j=0;j<n+2;j++)
		{
			mat[i][j] = pow(arr[i].f-arr[j].f, 2)+pow(arr[i].s-arr[j].s, 2);
		}
	}
/*	for(i=0;i<n+2;i++)
	{
		for(j=0;j<n+2;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
*/	priority_queue<pair<int, int>, vector<pair<int, int> >, comp > q;
	int visited[1003] = {0}, dist[1003];
	q.push(make_pair(0, 0));
	pair<int, int> ver;
	for(int k=0; k<1003;k++)
		dist[k] = INT_MAX;
	dist[0] = 0;
	while(!q.empty())
	{
		ver = q.top();
		q.pop();
		if(visited[ver.f] == 1)
		{
			continue;
		}
		visited[ver.f] = 1;
		if(ver.f == 1)
			break;
		for(i=0;i<n+2;i++)
		{
			if(i!=ver.f && visited[i]!=1)
			{
				if(dist[i] > (ver.s+ mat[ver.f][i]))
				{	
					dist[i] = ver.s + mat[ver.f][i];
					q.push(make_pair(i, dist[i]));
				}
			}
		}
	}
	printf("%d\n", dist[1]);
	return 0;
}

