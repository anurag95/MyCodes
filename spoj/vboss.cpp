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
struct node {
	int id;
	int money;
	int height;
};
bool cmp(const node& a, const node &b)
{
	return a.height<b.height;
}
int main()
{
	int t;
	si(t)
	while(t--)
	{
		int n, m, min, var;
		sii(n, m)
		int ind;
		int hash[1000010]={0};
		node emp[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d", &emp[i].id, &emp[i].money, &emp[i].height);
		}
		sort(emp, emp+n, cmp);
		for(int i=0;i<n;i++)
			hash[emp[i].id] = i;
		for(int i=0;i<m;i++)
		{
			si(var)
			if(hash[var]==n-1)
				printf("0 ");
			else {
				min = INT_MAX;
				for(int j=hash[var]+1;j<n;j++)
					if(min>emp[j].money)
					{
						min = emp[j].money;
						ind = j;
					}
				printf("%d ", emp[ind].id);
			}
			printf("%d\n", hash[var]);
		}
	}
	return 0;
}

