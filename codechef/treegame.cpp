#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[], int size)
{
	for(int i=1; i<=size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int t, n, u, v, i, l, r, max;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		max = 1;
		int height[10010] = {0}, nodes[10010] = {0};
		height[1] = 1;
		nodes[1] = 1;
		vector<int> vec[10010];
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d", &u, &v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		queue<int> q;
		q.push(1);
		while(!q.empty())
		{
			int var = q.front();
			q.pop();
			for(i=0;i<vec[var].size();i++)
			{
				if(height[vec[var][i]]!=0)
					continue;
				q.push(vec[var][i]);
				height[vec[var][i]] = height[var]+1;
				nodes[height[var]+1]++;
				if(height[var]+1 > max)
					max = height[var]+1;
			}
		}
		//printarray(nodes ,max);
		l = 1; r = max;
		int turn = 0;
		while(l<=r)
		{
			if(turn%2 == 0)
				l++;
			else  
			{
				nodes[r]--;
				if(nodes[r] == 0)
					r--;
			}
			turn = turn+1;
		}
		printf("%d\n", turn);
	}
	return 0;
}
