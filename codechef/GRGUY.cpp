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
char arr[2][200010];
int length;
int foo(int s){
	if(arr[s][0] == '#')
		return mod;
	int count=0, i=0, flag=0;
	while(i < length-1){
		if(arr[s][i+1] == '.')
			i++;
		else if(arr[(s+1)%2][i+1] == '.'){
			s = (s+1)%2;
			i++;
			count++;
		}
		else if(arr[(s+1)%2][i+1] == '.'){
			s = (s+1)%2;
			count++;
		}
		else return mod;
	}
	return count;
}
int main()
{
	int t;
	si(t)
	while(t--)
	{
		scanf("%s", arr[0]);
		scanf("%s", arr[1]);
		length = strlen(arr[0]);
		int change = min(foo(0), foo(1));
		if(change == mod)
			printf("No\n");
		else printf("Yes\n%d\n", change);
	}
	return 0;
}

