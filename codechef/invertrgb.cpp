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
int main()
{
	int t, f, s, mini, count;
	string str;
	si(t)
	while(t--)
	{
		cin>>str;
		mini = INT_MAX;
		int l = str.size();
		f = s = count = 0; //rgb
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'g')
				s++, count+=f;
			else if(str[i] == 'r')
				count+=(f+s);
			else if(str[i] == 'b')
				f++;
		}
		mini = min(mini, count);
		f = s = count = 0; //rbg
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'b')
				s++, count+=f;
			else if(str[i] == 'r')
				count+=(f+s);
			else if(str[i] == 'g')
				f++;
		}
		mini = min(mini, count);
		f = s = count = 0; //grb
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'r')
				s++, count+=f;
			else if(str[i] == 'g')
				count+=(f+s);
			else if(str[i] == 'b')
				f++;
		}
		mini = min(mini, count);
		f = s = count = 0; //gbr
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'b')
				s++, count+=f;
			else if(str[i] == 'g')
				count+=(f+s);
			else if(str[i] == 'r')
				f++;
		}
		mini = min(mini, count);
		f = s = count = 0; //brg
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'r')
				s++, count+=f;
			else if(str[i] == 'b')
				count+=(f+s);
			else if(str[i] == 'g')
				f++;
		}
		mini = min(mini, count);
		f = s = count = 0; //bgr
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'g')
				s++, count+=f;
			else if(str[i] == 'b')
				count+=(f+s);
			else if(str[i] == 'r')
				f++;
		}
		mini = min(mini, count);
		pi(mini);
	}
	return 0;
}

