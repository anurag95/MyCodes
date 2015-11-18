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
struct trie_node {
	int count;
	trie_node *children[26];
};
typedef struct trie_node trie_node;
trie_node* new_node()
{
	trie_node* node = (trie_node*)malloc(sizeof(trie_node));
	node->count = 0;
	for(int i=0;i<26;i++)
		node->children[i] = NULL;
	return node;
}
void insert(string s, trie_node* T)
{
	int len = s.size();
	trie_node *crawl = T;
	for(int i=0;i<len;i++){
		int index = s[i]-97;
		if(!crawl->children[index]){
			crawl->children[index] = new_node();
		}
		crawl = crawl->children[index];
	}
	crawl->count++;
}
int search(string s, trie_node* T)
{
	int len = s.size();
	trie_node *crawl = T;
	for(int i=0;i<len;i++)
	{
		int id = s[i]-97;
		if(!crawl->children[id])
			return 0;
		crawl = crawl->children[id];
	}
	return (crawl!=0 && crawl->count);
}
int main()
{
	trie_node* T = new_node();
	string str[8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	for(int i=0;i<8;i++)
		insert(str[i], T);
	printf("%s --- %d\n", "the", search("the", T) );
	printf("%s --- %d\n", "these", search("these", T) );
	printf("%s --- %d\n", "their", search("their", T) );
	printf("%s --- %d\n", "thaw", search("thaw", T) );
	return 0;
}

