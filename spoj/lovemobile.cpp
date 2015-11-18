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
int main()
{
	int n, arr[1010];
	si(n)
	while(n)
	{
		stack<int> s;
		int i;
		for(i=0;i<n;i++)
			si(arr[i])
		int cur = 1, instack = INT_MAX;
		for(i=0;i<n;i++)
		{
			if(arr[i] == cur)
				cur++;
			else {
				while(!s.empty() && s.top()==cur)
				{
					s.pop();
					cur++;
				}
				if(!s.empty() && arr[i]>s.top())
					break;
				s.push(arr[i]);
			}
		}
		if(i<n)
			printf("no\n");
		else printf("yes\n");
		si(n)
	}
	return 0;
}

