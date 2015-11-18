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
  
  int n, arr[305] = {0}, i;
  char matrix[301][301];
  scanf("%d", &n);
  int j, var, temp, flag;
  for(i=1;i<=n;i++)
    {
      scanf("%d", &var);
      arr[i] = var;
    }
  for(i=0;i<n;i++)
    scanf("%s", matrix[i]);
  for(i=1;i<=n;i++)
    {
      while(1)
	{
	  flag=0;
	  for(j=i;j>i;j--)
	    {
	      if(matrix[i-1][j-1] == '1')
		{
		  flag=1;
		  temp = arr[i];
		  arr[i] = arr[j];
		  arr[j] = temp;
		}
	    }
	  if(!flag)
	    break;
	}
    }
  printf("%d", arr[1]);
  for(i=2;i<=n;i++)
    printf(" %d", arr[i]);
  printf("\n");
  return 0;
}

