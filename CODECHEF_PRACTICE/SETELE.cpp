#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  ll n;
  scanf("%lld", &n);
  ll mstSum = 0;
  ll edgeCount = (n * (n - 1)) / 2;
  ll maxEdge = INT_MIN;
  for(int x = 0;x < n - 1;x++)
  {
    ll u, v, c;
    scanf("%lld %lld %lld", &u, &v, &c);
    mstSum += c;
    maxEdge = max(maxEdge, c);
  }
  ll ans = mstSum * (n - 2);
  ans += (edgeCount - n + 1)*(mstSum - maxEdge);
  long double e = ((long double)ans) / edgeCount;
  //printf(".6%lld")
  cout<<fixed<<setprecision(6)<<e<<endl;
  return 0;
}
