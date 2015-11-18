#include<bits/stdc++.h>
using namespace std;
pair<int, int> p[100020];
int main()
{
	int t, i, n, m, j;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		int arr[n];
		int answer[n];
		memset(answer, 0, sizeof(answer));
		for(i=0;i<n;i++)
			scanf("%d", &arr[i]);
		for(i=0;i<m;i++)
			scanf("%d%d", &p[i].first, &p[i].second);
		sort(p, p+m);
		for(i=0;i<m;i++)
		{
			if(answer[p[i].first] == 0)
				answer[p[i].first] = p[i].first;
			for(j=p[i].first;j<=p[i].second;j++)
				answer[j] = answer[p[i].first];
		}
		for(i=0;i<n;i++)
		{
			if(answer[i+1] != answer[arr[i]])
				break;
		}
		if(i!=n)
			printf("Impossible\n");
		else    printf("Possible\n");
	}
	return 0;
}


