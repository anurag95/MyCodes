#include<bits/stdc++.h>
using namespace std;
int main()
{
	int myxor=0, turn = 1, n, num1, num2, count1, count2;
	scanf("%d", &n);
	while(n--)
	{
		count1 = count2 = 0;
		scanf("%d", &num1);
		while(num1)
		{
			if(num1&1)
				count1++;
			num1>>=1;
		}
		myxor = myxor^count1;
	}
	if(myxor)
		printf("Shaka :)\n");
	else    printf("The other player :(\n");
	return 0;
}
