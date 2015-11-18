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
int findlevel(ll x)
{
	int level = 0;
	while(x!=1)
	{
		x/=2;
		level++;
	}
	return level+1;
}
int main()
{
	int q;
	si(q)
	ll x, y;
	int turn = 1;
	char str[4];
	while(q--)
	{
		int a, counter = 0;
		scanf("%s", str);
		if(str[1] == 'i'){
			turn = (turn + 1)%2;
		}
		else if(str[1] == 'r'){
			scanf("%lld%lld", &x, &y);
			while(x!=y)
			{
				if(x>y){
					a = findlevel(x);
					if(turn==1 && a%2==0)
						counter++;
					else if(!turn && a%2==1)
						counter++;
					x/=2;
				}
				else {
					a = findlevel(y);
					if(turn==1 && a%2==0)
						counter++;
					else if(!turn && a%2==1)
						counter++;
					y/=2;
				}
			}
			a = findlevel(x);
			if(turn==1 && a%2==0)
				counter++;
			else if(!turn && a%2==1)
				counter++;
			printf("%d\n", counter);
		}
		else {
			scanf("%lld%lld", &x, &y);
			while(x!=y)
			{
				if(x>y){
					a = findlevel(x);
					if(turn==1 && a%2==1)
						counter++;
					else if(!turn && a%2==0)
						counter++;
					x/=2;
				}
				else {
					a = findlevel(y);
					if(turn==1 && a%2==1)
						counter++;
					else if(!turn && a%2==0)
						counter++;
					y/=2;
				}
			}
			a = findlevel(x);
			if(turn==1 && a%2==1)
				counter++;
			else if(!turn && a%2==0)
				counter++;
			printf("%d\n", counter);
		}

	}
	return 0;
}

