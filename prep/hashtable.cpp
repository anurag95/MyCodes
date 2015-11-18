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

vector<vector<int> > table[50];
double load=0.75;
int num_ele=0;
int hash(int val)
{
	val = val^(val>>20)^(val>>12);
	val = val^(val>>7)^(val^4);
	return val;
}

void insert(int val)
{
	if(table.size()*load <= num_ele)
		table.resize(table.size()*2);
	int key = find_hash(val);
	for(int i=0;i<table[key].size();i++){
		if(table[key][i] == val)
			return ;
	}
	table[key].push_back(val);
	num_ele++;
}
pair<int, int> find(int val)
{
	int key = find_hash(val);
	for(int i=0;i<table[key].size();i++){
		if(table[key][i] == val)
			return make_pair(key, i);
	}
	return make_pair(-1, -1);
}
void erase(int val)
{
	int i;
	int key = find_hash(val);
	for(i=0;i<table[key].size();)
	{
		if(table[key][i] != val)
			i++;
		else break;
	}
	for(int j=i;j<table[key].size()-1;j++)
		table[key][j] = table[key][j+1];
	table[key].pop_back();
}
int main()
{
	int t;
	si(t)
	while(t--)
	{

	}
	return 0;
}

