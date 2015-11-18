#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sii(x,y) scanf("%d%d", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d ", x);
#define pll(x) printf("%lld\n", x);
void quicksort(int x[10],int first,int last){
	int pivot,j,temp,i;

	if(first>= last)
		return ;
	pivot=first;
	i=first+1;
	j=last;

	while(i<j){
		while(x[i]<=x[pivot]&&i<last)
			i++;
		while(x[j]>x[pivot])
			j--;
		if(i<j){
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
		}
	}

	temp=x[pivot];
	x[pivot]=x[j];
	x[j]=temp;
	quicksort(x,first,j-1);
	quicksort(x,j+1,last);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {1, 3, 2, 6, 3, 5, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	quicksort(arr, 0, n-1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
