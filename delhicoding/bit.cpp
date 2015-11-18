// functions update rangequery together constitute point update and range query

// functions rangeupdate query, together constitute range update and point query. This is inspite the fact that query returns [1..b]

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
int bit[10010], size;
void update(int idx, int val) // increase the value at idx by val
{
	for(; idx<= size; idx += (idx&(-idx)))
		bit[idx] += val;
}
int query(int idx) // return sum from [1..b]
{
	int sum = 0;
	for(;idx>0;idx-=(idx&(-idx)))
		sum += bit[idx];
	return sum;
}
int rangequery(int a, int b) // return sum from [a..b]
{
	return sum(b) - ((a==1)?0:sum(a-1));
}

void rangeupdate(int l, int r, int val)  // update values over a range
{
	update(l, val);
	update(r+1, -val);
}

int main()
{
	int t, u;
	scanf("%d", &t);
	while(t--)
	{
		memset(bit, 0, sizeof(bit));
		scanf("%d%d", &size, &u);
		int var, l, r;
		for(int i=0;i<u;i++)
		{
			scanf("%d%d%d", &l, &r, &var);
			rangeupdate(l+1, r+1, var);
		}
		int q, type = 1, x, y;
		si(q)
			while(q--)
			{
				scanf("%d", &x);
//				if(type == 1)
//				{
//					update(x, y);
//				}
//				else {
					printf("%d\n", query(x+1));
					//			printf("%d\n", rangequery(x, y));
	//			}
//				for(int i=0;i<size;i++)
//				{
//					printf("%d ", bit[i+1]);
//				}
//				printf("\n");
			}
	}
	return 0;
}

