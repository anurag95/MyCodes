#include<cstdio>
int lastdig(int num)
{
	int res = 0;
	while(num){
		res += num&1 ? num%10 : 2*(num%10);
		num /= 10;
	}
	return res%10;
}

int func(int num)
{
	int res = 0;
	while(num%10){
		res += lastdig(--num);
	}
	return res + 45*(num/10);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", func(b+1) - func(a));
	}
	return 0;
}

