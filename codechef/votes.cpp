#include<bits/stdc++.h>
#define ll long long
int main()
{
  int n, i, t;
  double arr[10010];
  scanf("%d", &t);
  while(t--){
    double sum=0, zeros=0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
      scanf("%lf", &arr[i]);
      sum+= arr[i];
      if(arr[i] == 0)
	zeros++;
    }
    if(sum<100)
      printf("NO\n");
    else {
      sum-=100;
      n-=zeros;
      if((sum/n)>=1)
	printf("NO\n");
      else printf("YES\n");
    }
  }
  return 0;
}
