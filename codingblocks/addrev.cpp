/* 
   add the reverse of two nnumbers and reverse it 
*/

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
int rev(int num)                     
{
	int temp=0;
	while(num)
	{
		temp=(temp*10)+(num%10);                 
		num/=10;
	}
	return temp;
}
int main()
{
	int t, a, b;
	si(t)
	while(t--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n",rev(rev(a)+rev(b)));
	}
	return 0;
}
