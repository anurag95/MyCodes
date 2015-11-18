#include <iostream>
using namespace std;
#define NUM_CHARS 256

char* remove_duplicates(char *s){
	int end = 0;
	bool hash[NUM_CHARS] = {0};
	for (int i = 0; s[i]; ++i){
		if(!hash[s[i]]){
			++hash[s[i]];
			s[end++] = s[i];
		}
	}
	s[end] = '\0';
	return s;
}

int main(){
	char s[100];
	cin>>s;
	cout<<remove_duplicates(s)<<endl;
	return 0;
}