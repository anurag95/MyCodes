#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t, i, j, length;
	char var[1000003];
	scanf("%d", &t);
	while(t--)
	{

		vector<int> palin;
		vector<int> copy;
		scanf("%s", var);
		i=0;
		while(var[i]!='\0')
		{
			palin.push_back(var[i]-48);
			i++;
		}
		for(i=0;i<palin.size();i++)
			copy.push_back(palin[i]);
		int len = copy.size();
		for(i=len-1;i>=len/2;i--)
			copy[i] = copy[len-1-i];
		i = len/2;
		j=i;
		int flag;
		if(len%2 == 0)
			j-=1;
		while(i<len && j>=0)
		{
			if (palin.size() != copy.size()) 
			{
				if(palin.size()<copy.size())
					break;
			}
			else {
				flag=0;
				for (int l = 0;l < palin.size(); l++)
					if (copy[l] != palin[l])
					{
						if(palin[l]<copy[l])
						{
							flag=1;
							break;
						}
						else if(copy[l]<palin[l])
							break;
					}
			}
			if(flag)
				break;
			copy[j]++;
			if(i!=j)
				copy[i]++;
			while(j>=0 && copy[j] == 10)
			{
				copy[j--] = copy[i++] = 0;
				if(j<0)
					break;
				copy[j]+=1;
				copy[i]+=1;
			}
			if(j<0)
			{
				copy[len-1] += 1;
				copy.insert(copy.begin(), 1);
				len++;
				j++;
			}
			i++;j--;
		}
		for(i=0;i<len;i++)
			printf("%d", copy[i]);
		printf("\n");
	}
	return 0;
}
