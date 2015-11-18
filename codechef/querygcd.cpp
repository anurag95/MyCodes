#include<bits/stdc++.h>
int gcd(int a, int b)
{
    int r;
    while(b){
	r=a%b;
	a=b;
	b=r;
    }
    return a;
}
int main()
{
    int i, l, r, t, n, q, arr[100010], prefix[100010], suffix[100010];
    scanf("%d", &t);
    while(t--){
	scanf("%d%d", &n, &q);
	scanf("%d", &arr[1]);
	prefix[1] = arr[1];
	for(i=2;i<=n;i++){
	    scanf("%d", &arr[i]);
	    prefix[i] = gcd(prefix[i-1], arr[i]);
	}
	suffix[n] = arr[n];
	for(i=n-1;i>0;i--){
	    suffix[i] = gcd(suffix[i+1], arr[i]);
	}
	for(i=0;i<q;i++){
	    scanf("%d%d", &l, &r);
	    if(l == 1)
		printf("%d\n", suffix[r+1]);
	    else if(r == n)
		printf("%d\n", prefix[l-1]);
	    else 
		printf("%d\n", gcd(prefix[l-1], suffix[r+1]));
	}
    }
    return 0;
}
