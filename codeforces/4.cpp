#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
	int i,flag=1;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int n;
	cin >> n;
	if(is_prime(n))
	{
		cout << "1" << endl;
		cout << n << endl;	
	}
	else
	{
		if(n%2==0)// even then one is 2
		{
			
		}
	}

