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
	int t;
	si(t)
	while(t--)
	{
		ll n, var, i, ans=0, flag, vill[100010][2], dino[100010][2];
		ll v = 0, d = 0, vsize = 0, dsize = 0;
		sll(n)
		for(i=0;i<n;i++)
		{
			flag = 0;
			sll(var)
			if(var > 0)
			{
				while(dsize)
				{
					flag = 0;
					if(var>=dino[d][0])
					{
						var -= dino[d][0];
						ans += (i - dino[d][1])*dino[d][0];
						d++;
						dsize--;
						if(!var)
							break;
					}
					else {
						dino[d][0] = dino[d][0] - var;
						ans += (i - dino[d][1])*var;
						var = 0;
						break;
					}
				}
				if(var)
				{
					vill[v+vsize][0] = var;
					vill[v+vsize][1] = i;
					vsize++;
				}
			}
			else if(var<0){
				var = -var;
				while(vsize)
				{
					flag = 0;
					if(var >= vill[v][0])
					{
						var -= vill[v][0];
						ans += (i - vill[v][1])*vill[v][0];
						v++;
						vsize--;
						if(!var)
							break;
					}
					else {
						vill[v][0] = vill[v][0] - var;
						ans += (i - vill[v][1])*var;
						var = 0;
						break;
					}
				}
				if(var)
				{
					dino[d+dsize][0] = var;
					dino[d+dsize][1] = i;
					dsize++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

