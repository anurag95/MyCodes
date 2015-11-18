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
#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	if(neg) x=-x;

}
int tree[400004], mincost[100002], lazy[400004];
int rating[100002];
ll knapsack[2][502];
pair<int, pair<int, int> >p[100002];
void rangeupdate(int l, int r, int c, int segindex, int start, int end)
{
	if(lazy[segindex] != mod){
		tree[segindex] = min(tree[segindex],lazy[segindex]);
		if(start != end){
			lazy[2*segindex+1] = min(lazy[2*segindex+1],lazy[segindex]);
			lazy[2*segindex+2] = min(lazy[2*segindex+2],lazy[segindex]);
		}
		lazy[segindex] = mod;
	}
	if(r<start || l>end || start>end){
		return ;
	}
	if(start>=l && end<=r){
		tree[segindex] = min(tree[segindex],c);
		if(start != end){
			lazy[2*segindex+1] = min(lazy[2*segindex+1],c);
			lazy[2*segindex+2] = min(lazy[2*segindex+2],c);
		}
		return ;
	}

	//int mid = end+(end-start)/2;
	int mid = (end+start)/2;
	rangeupdate(l, r, c, 2*segindex+1, start, mid);
	rangeupdate(l, r, c, 2*segindex+2, mid+1, end);
	tree[segindex] = min(tree[segindex*2+1], tree[segindex*2+2]);
}

int getmin(int start, int end, int l, int r, int index)
{
	if(lazy[index] != mod){
		tree[index] = min(tree[index],lazy[index]);
		if(start != end){
			lazy[2*index+1] = min(lazy[2*index+1],lazy[index]);
			lazy[2*index+2] = min(lazy[2*index+2],lazy[index]);
		}
		lazy[index] = mod;
	}
	if(l>end || r<start || start>end)    
		return mod;
	if(l<=start && r>=end)
		return tree[index];
	int mid = (end+start)/2;
	return min(getmin(start, mid, l, r, 2*index+1), getmin(mid+1, end, l, r, 2*index+2));
}

int main()
{
	int t;
	int n, k, m, i, j, l, r, c;
	ll sum;
	scanint(t);
	while(t--)
	{
		sum = 0;
		scanint(n);
		scanint(k);
		scanint(m);
		for(i=0;i<4*n+4;i++)
		{
			tree[i] = mod;
			lazy[i] = mod;
		}
		for(i=0;i<n;i++)
		{
			scanint(rating[i]);
			sum += (ll)rating[i];
		}
		for(i=0;i<m;i++)
		{
			//		scanf("%d%d%d", &l, &r, &c);
			scanint(l);
			scanint(r);
			scanint(c);
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
		int turn = 1;
		for(i=0;i<=k;i++)
			knapsack[0][i] = sum;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=k;j++){
				if(j>=mincost[i-1])
					knapsack[turn][j] = max(knapsack[(turn+1)%2][j], knapsack[(turn+1)%2][j-mincost[i-1]]-rating[i-1]);
				else knapsack[turn][j] = knapsack[(turn+1)%2][j];
			}
			turn = (turn+1)%2;
		}
		//		for(i=0;i<=n;i++)
		//		{
		//			for(j=0;j<=k;j++)
		//				printf("%lld ", knapsack[i][j]);
		//			printf("\n");
		//		}
		printf("%lld\n", knapsack[(turn+1)%2][k]);

	}
	return 0;
}

