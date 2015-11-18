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
map<string, int> M;
int main()
{
	int t, i, k, l, n;
	string word[100], str;
	si(t)
	while(t--)
	{
		scanf("%d", &n);
		si(l);
		for(i=0;i<n;i++){
			cin>>word[i];
			M[word[i]] = 0;
		}
		for(i=0;i<l;i++)
		{
			si(k);
			for(int j=0;j<k;j++){
				cin>>str;
				M[str] += 1;
//				printf("%s %d\n", str, M[str]);
			}
		}
		map<string, int>::iterator it;
//		for(it=M.begin(); it!=M.end(); it++)
//			printf("%s %d\n", it->first, it->second);
//		printf("%d\n", M[word[0]]);
		if(M[word[0]] != 0)
			printf("YES");
		else 
			printf("NO");
		for(i=1;i<n;i++){
			if(M[word[i]] != 0)
				printf(" YES");
			else 
				printf(" NO");
		}
		printf("\n");
	}
	return 0;
}

