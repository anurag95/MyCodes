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

void func(vector<int> arr)
{
	int last = arr[0], start = arr[0], cnt = 1;
	int sz = arr.size();
	for(int i=1;i<sz;i++)
	{
		if(arr[i] == last+1){
			cnt++;
			last = arr[i];
		}
		else {
			if(cnt > 1)
				printf("%d-%d, ", start, last);
			else printf("%d, ", start);
			cnt = 1;
			start = last = arr[i];
		}
	}
	if(cnt > 1)
		printf("%d-%d\n", start, last);
	else printf("%d\n", start);

}

int main()
{
	int myint[] = {1,2,3,10,25,26,30,31,36};
	vector<int> v(myint, myint+9);
	func(v);
	return 0;
}

