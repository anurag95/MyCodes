#include<stdio.h>
int main()
{
	int a,b,c,d,e,x,y,z;
	int i;
	int j;
	printf ("enter the date");
	scanf ("%d %d %d",&z,&y,&x);
	i=0;
	int k;
	for (a=1900;a<=x;a++)
	{ if(a==x)
		{
			j=y;
		}
		else
		{
			j=12;
		}
		for (b=1;b<=j;b++)
		{
			if (b==1||b==3||b==5||b==7||b==8||b==10||b==12)
				d=31;
			if (b==4||b==6||b==9||b==11)
				d=30;
			if (a%400==0||a%100!=0&&a%4==0)
			{
				if (b==2)
				{
					d=29;
				}


			}
			else
			{
				if (b==2)
				{
					d=28;
				}
			}
			if(a==x&&b==y)
			{
				d=z;
			}
			for (k=1;k<=d;k++)
			{
				i = i+1;
			}
		}
	}
	i=i%7;
	if (i==0)
	{
		printf ("SUNDAY");
	}
	if (i==1)
	{
		printf ("MONDAY");
	}
	if (i==2)
	{
		printf ("TUESDAY");
	}
	if (i==3)
	{
		printf ("WEDNESDAY");
	}
	if (i==4)
	{
		printf ("THURSDAY");
	}
	if (i==5)
	{
		printf ("FRIDAY");
	}
	if (i==6)
	{
		printf ("SATURDAY");
	}

}
