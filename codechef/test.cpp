#include<stdio.h>
int main()
{
	//clrscr();
	long arr[1000];
	long arrans[1000];

	arr[0]=1L;
	arrans[0]=1L;
	long ans=0L;
	long temp=0L;
	int j=0;

	long int mod=1000000007L;


	for(int i=1;i<1000;i++)
	{

		ans=arr[i-1];

		for(j=0;j<i;j++)
		{

			temp=arr[j];
			arr[j]=ans;
			ans=ans+temp;

			ans=ans%mod;

		}
		arr[j]=ans;
		arrans[j]=ans;
	}

	//int cases=1000;
	int cases;
	scanf("%d",&cases);



	int n;
	for(int h=0;h<cases;h++)
	{
		scanf("%d",&n);
		//n=h+1;

		printf("%ld\n",arrans[n-1]);
	}

	//getch();
	return 0;
}
