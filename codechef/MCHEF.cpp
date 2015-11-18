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
#define mp make_pair
#define x first
#define y second
int tree[400004], mincost[100002], lazy[400004];
int rating[100002];
ll knapsack[100002][502];
pair<int, pair<int, int> >p[100002];
void rangeupdate(int l, int r, int c, int segindex, int start, int end)
{
	if(lazy[segindex] != mod){
		tree[segindex] = lazy[segindex];
		if(start != end){
			lazy[2*segindex+1] = lazy[segindex];
			lazy[2*segindex+2] = lazy[segindex];
		}
		lazy[segindex] = mod;
	}
	if(r<start || l>end || start>end){
		return ;
	}
	if(start>=l && end<=r){
		tree[segindex] = c;
		if(start != end){
			lazy[2*segindex+1] = c;
			lazy[2*segindex+2] = c;
		}
		return ;
	}

	int mid = (start + end)/2;
	rangeupdate(l, r, c, 2*segindex+1, start, mid);
	rangeupdate(l, r, c, 2*segindex+2, mid+1, end);
	tree[segindex] = min(tree[segindex*2+1], tree[segindex*2+2]);
}

int getmin(int start, int end, int l, int r, int index)
{
	if(l>end || r<start || start>end)    
		return mod;
	if(lazy[index] != mod){
		tree[index] = lazy[index];
		if(start != end){
			lazy[2*index+1] = lazy[index];
			lazy[2*index+2] = lazy[index];
		}
		lazy[index] = mod;
	}
	if(l<=start && r>=end)
		return tree[index];
	int mid = (start+end)/2;
	return min(getmin(start, mid, l, r, 2*index+1), getmin(mid+1, end, l, r, 2*index+2));
}

int main()
{
	int t;
	int n, k, m, i, j, l, r, c;
	ll sum;
	si(t)
	while(t--)
	{
		sum = 0;
		si(n);
		si(k);
		si(m);
		for(i=0;i<4*n+4;i++)
			lazy[i] = mod;
		for(i=0;i<n;i++)
		{
			scanf("%d", &rating[i]);
			sum += (ll)rating[i];
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d", &l, &r, &c);
			l--; r--;
			p[i] = mp(c, mp(l, r));
		}
		sort(p, p+m);
		for(i=m-1;i>=0;i--)
		{
			rangeupdate(p[i].y.x, p[i].y.y, p[i].x, 0, 0, n-1);
		}
		for(i=0;i<n;i++)
		{
			mincost[i] = getmin(0, n-1, i, i, 0);
		}
//		for(i=0;i<n;i++)
//		{
//			pi(mincost[i]); // = getmin(0, n-1, i, i, 0);
//		}
		for(i=0;i<=k;i++)
			knapsack[0][i] = sum;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=k;j++){
				if(j>=mincost[i-1])
					knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-mincost[i-1]]-rating[i-1]);
				else knapsack[i][j] = knapsack[i-1][j];
			}
		}
//		for(i=0;i<=n;i++)
//		{
//			for(j=0;j<=k;j++)
//				printf("%lld ", knapsack[i][j]);
//			printf("\n");
//		}
		printf("%lld\n", knapsack[n][k]);
		
	}
	return 0;
}

