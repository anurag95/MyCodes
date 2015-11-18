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
int counter = 2;
int isLucky(int n)
{

	/*variable next_position is just for readability of
	  the program we can remove it and use n only */
	int next_position = n;
	if(counter > n)
		return 1;
	if(n%counter == 0)
		return 0;      

	/*calculate next position of input no*/
	next_position -= next_position/counter;

	counter++;
	return isLucky(next_position);
}
/*int islucky(int n)
{
	int counter = 2;
	while(1){
		if(n < counter)
			return 1;
		else if(n%counter == 0)
			return 0;
		n -= (n/counter);
		counter++;
	}
} */
int main()
{
	for(int i=1;i<100;i++){
		counter = 2;
		if(isLucky(9)) printf("%d ", i);
	}
	printf("\n");
	return 0;
}

