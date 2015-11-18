#include<bits/stdc++.h>
#define ll long long
int main()
{
  ll t, n, k, a[100010], b[100010];
  scanf("%lld", &t);
  while(t--){
    scanf("%lld%lld", &n, &k);
    ll var, i;
    ll ma=0;
    for(i=0;i<n;i++)
      scanf("%lld", &a[i]);
    for(i=0;i<n;i++)
      scanf("%lld", &b[i]);
    for(i=0;i<n;i++){
      var = (k/a[i])*b[i];
      if(ma<var)
	ma = var;
    }
    printf("%lld\n", ma);
  }
  return 0;
}

