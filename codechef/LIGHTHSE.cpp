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
struct str{
	int x;
	int y;
}a[4];
int main()
{
	int i, t, n, x, y, ind[4];
	pair<int, int> p[500001], inv[500001];
	si(t);
	while(t--)
	{
		si(n);
		int maxy=INT_MIN, miny=INT_MAX, indmax, indmin;
		int maxx=INT_MIN, minx=INT_MAX;
		for(i=0;i<n;i++)
		{
			scanf("%d%d", &x, &y);
			p[i] = make_pair(x, y);
			inv[i] = make_pair(y, x);
			if(maxy <= y){
				maxy = y;
				if(maxx <= x){
					maxx = x; 
					ind[3] = i+1;
				}
				else if(minx <= x){
					minx = x;
					ind[1] = i+1;
				}
				indmax = i+1;
			}
			if(miny > y){
				miny = y;
				if(maxx <= x){
					maxx = x; 
					ind[2] = i+1;
				}
				else if(minx <= x){
					minx = x;
					ind[0] = i+1;
				}
				indmin = i+1;
			}
		}
		if(n == 1){
			printf("1\n1 NE\n");
			continue;
		}
		sort(inv, inv+n);
		sort(p, p+n);
		if(inv[0].second < inv[n-1].second)
		{
			if(p[0].first == inv[0].second)
				printf("1\n%d NE\n", ind[0]);
			else if(p[n-1].first == inv[n-1].second)
				printf("1\n%d SW\n", ind[3]);
			else 
				printf("2\n%d NE\n%d SW\n", indmin, indmax);
		}
		else if(inv[0].second > inv[n-1].second){
			if(p[n-1].first == inv[0].second)
				printf("1\n%d NW\n", ind[2]);
			else if(p[0].first == inv[n-1].second)
				printf("1\n%d SE\n", ind[1]);
			else 
				printf("2\n%d NW\n%d SE\n", indmin, indmax);
//			printf("%d NW\n%d SE\n", indmin, indmax);
		}
		else {
			if(p[0].first == inv[0].second)
				printf("1\n%d NE\n", ind[0]);
			else if(p[n-1].first == inv[n-1].second)
				printf("1\n%d SW\n", ind[3]);
			else if(p[n-1].first == inv[0].second)
				printf("1\n%d NW\n", ind[2]);
			else if(p[0].first == inv[n-1].second)
				printf("1\n%d SE\n", ind[1]);
			else
				printf("2\n%d NW\n%d SE\n", indmin, indmax);
		}
	}
	return 0;
}

