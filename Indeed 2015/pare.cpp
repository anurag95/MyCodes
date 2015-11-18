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
	int t, n;
	char str[10002];
	stack<char> s;
	si(t)
	while(t--)
	{
		scanf("%s", str);
		int l = strlen(str);
		if(l%2 == 1){
			printf("IMPOSSIBLE\n");
			continue;
		}
		int i;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i] == '(')
				s.push(str[i]);
			else {
				if(!s.empty() && s.top() == '(')
					s.pop();
				else s.push(')');
			}
		}
		int c=0, x=0;
		int flag = 0, flag2 = 0;
		char ch, prev;
		while(!s.empty())
		{
			if(s.top() == ')')
			{
				flag=1;
				c++;
			}
			else if(s.top() == '(')
			{
				flag2=1;
				x++;
			}
			s.pop();
		}
		if(!flag)
			printf("%d\n", x/2);
		else if(!flag2)
			printf("%d\n", c/2);
		else {
			int ans = 0;
			if(c%2 == 1)
				ans += c/2+1;
			else ans += c/2;
			if(x%2 == 1)
				ans += x/2+1;
			else ans += x/2;
			printf("%d\n", ans);
		}
	}
	return 0;
}

