#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
/*inline void inp(int &n)
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}*/
#define gc getchar_unlocked

void inp(int &x)
{
	    register int c = gc();
	        x = 0;
		    for(;(c<48 || c>57);c = gc());
		        for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int last[8000005], str[1000001], dp[1000001];
int sum[1000015];
int main()
{
	int t, n, i, x;
	inp(t);
	while(t--)
	{
		inp(n);
		inp(str[0]);
		for(i=1;i<n;i++)
		{
			inp(str[i]);
			str[i-1] = -str[i-1]+4000001+str[i];
			last[str[i-1]] = -1;
		}
		sum[0] = 1;
		for(i=0;i<n-1;i++)
		{
			x = str[i];
			dp[i+1] = sum[i] - (last[x]==-1?0:sum[last[x]-1]);
			while(dp[i+1]<0) dp[i+1]+=mod; while(dp[i+1]>=mod)dp[i+1]-=mod;
			last[x] = i+1;
			sum[i+1] = sum[i]+ dp[i+1];
			while(sum[i+1]>=mod) sum[i]-=mod;
		}
		if(sum[n-1]) sum[n-1]--; else sum[n-1] = 1000000008;
		printf("%d\n", sum[n-1]);
	}
	return 0;
}
