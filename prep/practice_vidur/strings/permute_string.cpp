#include <iostream>
using namespace std;

void permute(char* s, int l, int r){
	if(l == r){
		cout<<s<<endl;
		return;
	}
	for (int i = l; i <= r; ++i)
	{
		swap(s[i],s[l]);
		permute(s,l+1,r);
		swap(s[l],s[i]);
	}
	return;
}

int main(){
	char s[100];
	cin>>s;
	cout<<endl;
	int n = 0;
	while(s[n]) ++n;
	permute(s,0,n-1);
	return 0;
}