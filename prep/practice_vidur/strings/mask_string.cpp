#include <iostream>
using namespace std;
#define NUM_CHARS 256
char* mask_string(char* s1, char* s2){
	bool hash[NUM_CHARS] = {0};
	for (int i = 0; s2[i]; ++i){
		hash[s2[i]] = 1;
	}
	int end = 0;
	for (int i = 0; s1[i]; ++i){
		if(!hash[s1[i]]){
			s1[end++] = s1[i];
		}
	}
	s1[end] = '\0';
	return s1;
}

int main(){
	char s1[100], s2[100];
	cin>>s1>>s2;
	cout<<endl;
	cout<<mask_string(s1,s2)<<endl;
	return 0;
}