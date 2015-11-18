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
int checkprime(int n)
{
	int i=2, d = sqrt(n);
	for(;i<=d;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int array[] = {2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921};
int main()
{
	int t, a, b;
	si(t);
	int count;
	while(t--)
	{
		count=0;
		sii(a, b);
		for(int i=0;i<37;i++)
		{
			if(array[i]>=a && array[i]<=b)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}

