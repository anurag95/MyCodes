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
int primes[10010] = {0};
bool isprime(int n)
{
	int d = sqrt(n);
	for(int i=2;i<=d;i++)
		if(n%i == 0)
			return false;
	return true;
}
int main()
{
//	cout<<isprime(39)<<endl;
	for(int i=2;i<10005;i++)
		if(isprime(i))
			primes[i] = 1;
//	for(int i=0;i<10000;i++)
//		if(primes[i])
//			cout << i << " ";
//	cout<<endl;
	int t;
	si(t)
	while(t--)
	{
		char s[10010];
		int arr[128] = {0}, max = -1;
		cin>>s;
		for(int i = 0;s[i];i++)
		{
			arr[s[i]]++;
			if(arr[s[i]] > max)
				max = arr[s[i]];
		}
//		for(int i = 0;i<128;i++)
//		{
//			cout<<arr[i]<<" ";
//		}
//		cout<<endl<<max;
		int count = 0;
		if(max == 1)
		{
			count = strlen(s);
		}
		else if(primes[max])
		{
			for(int i=0;i<128;i++)
			{
				if(primes[arr[i]] && arr[i]!=1)
					count += (arr[i]- arr[i]/2);
				else count += arr[i];
			}
		}
		else if(!primes[max])
		{
			for(int i=0;i<128;i++)
			{
				if((!primes[arr[i]]) && (arr[i]!=1))
					count += (arr[i] - arr[i]/2);
				else count += arr[i];
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
