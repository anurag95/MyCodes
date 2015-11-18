#include<bits/stdc++.h>
using namespace std;
int post[8010], ind=0;
int search(int arr[], int x, int n)
{	
	for(int i=0;i<n;i++)
		if(arr[i] == x)
			return i;
	return -1;
}
int postorder(int in[], int pre[], int n)
{
	int root = search(in, pre[0], n);
	if(root!=0)
	{
		if(postorder(in, pre+1, root) == 0)
			return 0;
	}
	if(root!=n-1)
	{
		if(postorder(in+root+1, pre+root+1, n-root-1)==0)
			return 0;
	}
	if(pre[0] != post[ind++])
		return 0;
	return 1;
}
int main()
{
	int n, in[8010], pre[8010], i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &pre[i]);
	for(i=0;i<n;i++)
		scanf("%d", &post[i]);
	for(i=0;i<n;i++)
		scanf("%d", &in[i]);
	if(postorder(in, pre, n))
		printf("yes\n");
	else    printf("no\n");
	return 0;
}

