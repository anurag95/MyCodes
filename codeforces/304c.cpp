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
int n, k1, k2, arr1[10], arr2[10];
deque<int> q1, q2;

int check()
{
	int i=0;
	deque<int>::iterator it;
	it = q1.begin();
	while(it!=q1.end())
	{
		if(*it != arr1[i])
			return 0;
		it++;
		i++;
	}
	it = q2.begin();
	i=0;
	while(it!=q2.end())
	{
		if(*it != arr2[i])
			return 0;
		it++;
		i++;
	}
	return 1;
}
int main()
{
	si(n)
	int i, var;
	si(k1)
	for(i=0;i<k1;i++){
		cin>>var;
		q1.push_back(var);
		arr1[i] = var;
	}
	int winner = 0;
	si(k2)
	for(i=0;i<k2;i++){
		cin>>var;
		q2.push_back(var);
		arr2[i] = var;
	}
	int count=0;
	while(true){
		count++;
		int c1 = q1.front();
		int c2 = q2.front();
		q1.pop_front();
		q2.pop_front();

		if(c1>c2){
			winner = 1;
			q1.push_back(c2);
			q1.push_back(c1);
		}
		else if(c1<c2){
			winner = 2;
			q2.push_back(c1);
			q2.push_back(c2);
		}
		if(q1.size()==0 || q2.size()==0)
			break;
		if(count > 40000000){
			winner = 0;
			break;
		}
/*		if(q1.size()==k1 && q2.size()==k2)
		{
			if(check()){
				winner = 0;
				break;
			}
		}
*/	}
	if(!winner)
		pi(-1)
	else printf("%d %d\n", count, winner);
	return 0;
}

