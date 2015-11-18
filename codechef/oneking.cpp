#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, int> p[100010];
    int t, n, i, a, b;
    scanf("%d", &t);
    while(t--){
	scanf("%d", &n);
	for(i=0;i<n;i++){
	    scanf("%d%d", &a, &b);
	    p[i].first = b;
	    p[i].second = a;
	}
	int count=0;
	sort(p, p+n);
	int last=-1;
	for(i=0;i<n;i++){
	    if(p[i].second > last){
			count++;
			last=p[i].first;
	    }
	}
	printf("%d\n", count);
    }
    return 0;
}
	    
	
	
    
