#include<bits/stdc++.h>
int main()
{
	long long int t, n, k, d1, d2;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
		if(n%3)
			printf("no\n");
		else if(n-k-d1-d2>=0 && (n-k-d1-d2)%3 == 0)
			printf("yes\n");
		else if(n-k-d1-2*d2 >=0 && (n-k-d1-2*d2)%3==0)
			printf("yes\n");
		else if(n-k-d2-2*d1 >=0 && (n-k-d2-2*d1)%3==0)
			printf("yes\n");
		else if(d1>d2 && n-k-2*d1+d2>=0 && (n-k-2*d1+d2)%3==0)
			printf("yes\n");
		else if(d1<=d2 && n-k-2*d2+d1>=0 && (n-k-2*d2+d1)%3==0)
			printf("yes\n");
		else    printf("no\n");
	}
	return 0;
}
