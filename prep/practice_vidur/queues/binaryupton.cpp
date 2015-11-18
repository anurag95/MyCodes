#include <iostream>
#include <queue>
using namespace std;

void binaryupton(int n)
{
	queue <string> q;
	q.push("1");
	while(n--)
	{
		string s1 = q.front();
		q.pop();
		cout<<s1<<endl;
		q.push(s1+"0");
		q.push(s1+"1");

	}
}

int main()
{
	int n;
	cin>>n;
	binaryupton(n);
	return 0;
}