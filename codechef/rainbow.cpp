#include<bits/stdc++.h>
#define max 1000000007
using namespace std;
#define ll long long int 
ll gcd(ll a, ll b)
{
	ll r;
	while(b!=0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int modinv(int a, int x, int mod)
{
	int res = 1;
	while(x > 0) {
		if( x % 2 != 0) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		x /= 2;
	}
	return res;
}
int main()
{
	ll n, i, ans=1, arr[7], r, j;
	scanf("%lld", &n);
	n-=13;
	if(n<0)
		printf("0\n");
	else {
		if(n%2)
			n--;
		n/=2;
		//for(i=6;i>0;i--)
		//	ans = (ans*(n+i))%max;
		for(i=1;i<7;i++)
			arr[i] = n+i;
		for(i=2;i<=6;i++)
		{
			r = i;
			for(j=1;j<7;j++)
			{
				if(r==1)
					break;
				int g = gcd(arr[j], r);
				r/=g;
				arr[j]/=g;
			}
		} 
	//	for(i=1;i<7;i++)
	//		printf("%d\n", arr[i]);
		for(i=1;i<7;i++)
			ans = (ans*arr[i])%max;
		printf("%lld\n", ans);
		//printf("%d\n", modinv(720, max-2, max)%max);
		//printf("%d\n", (ans*(modinv(720, max-2, max)))%max);
	}
	return 0;
}
