#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,bool> a, pair<int,bool> b)
{
	return a.first < b.first;
}
int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	while(t--)
	{

		pair<int,bool> p;
		vector <pair<int,bool> > v;
		vector <pair<int,bool> >::iterator it;
		scanf("%d", &n);
		int a, b;
		for(i=0;i<n;i++)
		{
			scanf("%d%d", &a, &b);
			p.first=a;
			p.second=true;
			v.push_back(p);
			p.first=b;
			p.second=false;
			v.push_back(p);
		}
		sort(v.begin(), v.end(), cmp);
		int count=0, ans=0;
		for(it=v.begin();it!=v.end();it++)
		{
			if((*it).second == true)
				count++;
			else count--;
			ans = max(ans, count);
		}
		printf("%d\n", ans);
	}
	return 0;
}
