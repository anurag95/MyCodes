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
int arr[10100], sieve[1300]={0};

void makesieve()
{
	int i, num = 2;
	memset(arr, 0, 10100);
	memset(sieve, 0, 1300);
	for(num=2;num<10100;num++)
	{
		if(arr[num]!=-1)
		{
			for(int j=2*num;j<10100;j+=num)
			{
				arr[j] = -1;
			}
		}
	}
	for(i=0,num=2;num<10100;num++)
	{
		if(arr[num]!=-1)
			sieve[i++] = num;
	}
}
int main()
{
	makesieve();
	int n, i, copy, prime, power[10100]={0};
	//for(i=0;i<10;i++)
	//	printf("%d ", sieve[i]);
	si(n)
	for(i=0;i<1235 && sieve[i]!=0;i++)
	{
		prime = sieve[i];
		copy = n;
		while(copy/prime != 0)
		{
			//printf("%d\n", prime);
			power[sieve[i]] += copy/prime;
			prime*=sieve[i];
		}
	}
	printf("2^%d", power[2]);
	for(i=3;i<10100;i++)
	{
		if(power[i]!=0)
			printf(" * %d^%d", i, power[i]);
	}
	printf("\n");
	return 0;
}

