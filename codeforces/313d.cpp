#include<bits/stdc++.h>
using namespace std;
bool func(string a, string b)
{
	if(a==b)
		return true;
	if(a.size()%2 || a.size()!=b.size() || b.size()%2)
		return false;
	string a1, a2, b1, b2;

	a1 = a.substr(0, a.size()/2);
	a2 = a.substr(a.size()/2, a.size()/2);
	b1 = b.substr(0, b.size()/2);
	b2 = b.substr(b.size()/2, b.size()/2);
	if(func(a1,b2) && func(a2,b1)) return true;
	if(func(a1,b1) && func(a2,b2)) return true;
	return false;
}
int main ()
{
	string x,y;
	cin>>x;
	cin>>y;
	if(func(x, y)) printf("YES\n");
	else printf("NO\n");
	return 0;
}

