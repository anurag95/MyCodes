#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
 
void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
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
	int num;
	plank p[100020];
	int count=0;
	scanint(num);
	for(int i=0;i<num;i++)
	{
		scanint(p[i].start);
		scanint(p[i].end);
		p[i].end+=p[i].start;
	}
	sort(p, p+num, cmp);
	int endd = -1;
	for(int i=0;i<num;i++)
	{
		if(p[i].start > endd)
		{
			count++;
			endd = p[i].end;
		}
	}
	printf("%d\n", count);
	return 0;
}
