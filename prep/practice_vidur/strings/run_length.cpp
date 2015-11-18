#include <iostream>
#include <cstdio>
using namespace std;

char *encode(char *s1){
	int n;
	for (n = 0; s1[n]; ++n);
	char count[100];
	char *s2 = new char[sizeof(s1)*n*2+1];
	int end = 0;
	for (int i = 0; i < n; ++i){
		s2[end++] = s1[i];
		int cnt = 1;
		while(i+1 < n && s1[i+1] == s1[i]){
			++cnt;
			++i;
		}
		sprintf(count,"%d",cnt);
		for (int k = 0; count[k]; ++k){
			s2[end++] = count[k];
		}
	}
	s2[end] = '\0';
	return s2;
}

int main(){
	char s[100];
	cin>>s;
	cout<<encode(s)<<endl;
	return 0;
}