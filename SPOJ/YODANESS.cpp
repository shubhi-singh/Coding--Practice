#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int bit[30000];
string ar[30000];
string ar2[30000];
int idxMap[30000];
int n;
void add(int idx, int delta)
{
  for(;idx < n;idx = idx | (idx + 1))
    bit[idx] += delta;
}
int sum(int r)
{
  int ret = 0;
  for(;r >= 0;r = (r & (r + 1)) - 1)
    ret += bit[r];
  return ret;
}
int sum(int l, int r)
{
  return sum(r) - sum(l - 1);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    map<string, int> key;
    for(int x = 0 ;x < n;x++)
    {
      cin>>ar[x];
      key[ar[x]] = x;
    }
    for(int x = 0;x < n;x++)
    {
      cin>>ar2[x];
      idxMap[key[ar2[x]]] = x;
    }
    for(int x = 0;x < n;x++)
    {
      //cout<<idxMap[x]<<endl;
      add(x, 1);
    }
    ll ans = 0;
    for(int x = 0;x < n;x++)
    {
      int idx = idxMap[x];
      int q = sum(0, idx - 1);
      //cout<<q<<endl;
      ans += q;
      add(idx, -1);
    }
    cout<<ans<<endl;


  }
  return 0;
}
