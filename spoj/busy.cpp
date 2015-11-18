#include<bits/stdc++.h>
using namespace std;
struct plank {
	int start;
	int end;
};
bool cmp(const plank &a, const plank &b)
{
	return a.end < b.end;
}
int main()
{
	int t, s, e, num;
	scanf("%d", &t);
	while(t--)
	{
		plank p[100020];
		int count=0;
		scanf("%d", &num);
		for(int i=0;i<num;i++)
			scanf("%d%d", &p[i].start, &p[i].end);
		sort(p, p+num, cmp);
		int endd = -1;
		for(int i=0;i<num;i++)
		{
			if(p[i].start >= endd)
			{
				count++;
				endd = p[i].end;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}


