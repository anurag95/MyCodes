#include<bits/stdc++.h>
using namespace std;
struct s {
	int n;
	int ind;
};
bool cmp(const s &a, const s &b)
{
	return a.n < b.n;
}
int comp(const void *a, const void *b)
{
	 struct s *mi1 = (struct s *) a;
	            struct s *mi2 = (struct s *) b;
		               return mi1->n - mi2->n;


}
int main()
{
	int a, b, i, n, var;
	scanf("%d%d%d", &n, &a, &b);
	s arr[n];
	int ans[n], sor[n];
	int* lower;
	for(i=0;i<n;i++)
		ans[i] = -1;
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i].n);
		arr[i].ind = i;
	}
	sort(arr, arr+n, cmp);
	for(i=0;i<n;i++)
		sor[i] = arr[i].n;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(ans[arr[i].ind]==-1)
		{
			var = a-arr[i].n;
			lower = lower_bound(sor, sor+n, var);

			if(*lower == a-arr[i].n)
				ans[lower] = 1;
			else {
				var = b-arr[i].n;
				lower = lower_bound(sor, sor+n, var);

				if(sor[lower] == a-arr[i].n)
					ans[lower] = 1;
				else {
					flag=1;
					break;
				}
			}
		}
	}
	if(flag == 1)
		printf("NO\n");
	else   {
		printf("YES\n%d", ans[0]);
		for(i=1;i<n;i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
