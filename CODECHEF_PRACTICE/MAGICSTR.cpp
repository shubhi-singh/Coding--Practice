#include <bits/stdc++.h>
#define ll long long int
#define NMAX 2000
#define MOD 1000000007
using namespace std;
ll st[4 * NMAX];
ll combine(ll a, ll b)
{
  return ((a % MOD) * (b % MOD)) % MOD;
}
void build(int ar[], int v, int tl, int tr)
{
  if(tl == tr)
  {
    st[v] = ar[tl];
    return;
  }
  int mid = (tl + tr) / 2;
  build(ar, v * 2, tl, mid);
  build(ar, v * 2 + 1, mid + 1, tr);
  st[v] = combine(st[v * 2], st[v * 2 + 1]);
}
ll update(int v, int tl, int tr, int l, int r)
{
  if(l >  r)
    return st[v];
  if(tl == l && tr == r)
  {
    st[v] = 1;
  }
  else
  {
  int mid = (tl + tr) / 2;
  ll left = update(v * 2, tl, mid, l, min(mid, r));
  ll right = update(v * 2 + 1, mid + 1, tr, max(mid + 1, l), r);
  st[v] = min(st[v], combine(left, right));
}
  //cout<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<st[v]<<endl;
  return st[v];
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    int ar[2000];
    for(int x = 0;x < n;x++)
      ar[x] = 26;
    build(ar, 1, 0, n - 1);
    while(m--)
    {
      int l,  r;
      scanf("%d %d", &l, &r);
      l = l - 1;
      r = r - 1;
      int mid = (l + r) / 2;
      update(1, 0, n - 1, mid + 1, r);
    }
    cout<<st[1]<<endl;

  }
  return 0;
}
