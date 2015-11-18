#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, num, den, turn;
	scanf("%d", &t);
	while(t--)
	{
		int i;
		int sum=0;
		scanf("%d", &n);
		int copy = n;
		for(i=1;;i++)
		{
			sum = sum+i;
			if(sum>=n)
				break;

		}
		int temp = n - (sum-i);
		if(i%2 == 0)
		{
			num = temp;
			den = i+1-temp;
		}
		else {
			num = i+1-temp;
			den = temp;
		}

		printf("TERM %d IS %d/%d\n", copy, num, den);
	}
	return 0;
}

