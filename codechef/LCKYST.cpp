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
	int n;
//	for(int i=11;i<10000;i++)
//		if((i*47)%100 == 0)
//			printf("%d\n", i);
	ll var;
	si(n)
	while(n--)
	{
		scanf("%lld", &var);
		while(1){
			int flag=0;
			ll copy = var;
			while(copy != 0){
				if(copy%10 == 5){
					var*=4;
					flag = 1;
					break;
				}
				else if(copy%10 != 0)
					break;
				copy/=10;
			}
			if(!flag)
				break;
		}
		printf("%lld\n", var);
	}
	return 0;
}

