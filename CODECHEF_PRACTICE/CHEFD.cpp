#include <bits/stdc++.h>
#define NMAX 100010
using namespace std;
struct tnode
{
  int q1;
  int q2;
  int q3;
};
tnode st[4 * NMAX];
tnode undo[NMAX];
int ar[NMAX];
tnode combine(tnode a, tnode b)
{
  a.q1 += b.q1;
  a.q2 += b.q2;
  a.q3 += b.q3;
  return a;
}
void build(int v, int tl, int tr)
{
  st[v] = (tnode){0, 0, 0};
  int mid = (tl + tr) / 2;
  build(v * 2, tl, mid);
  build(v * 2 + 1, mid + 1, tr);
  return;
}
void update(int v, int tl , int tr, int l, int r, tnode up)
{
  if(l > r)
    return;
  if(tl == l && tr == r)
  {
    st[v].q1 += up.q1;
    st[v].q2 += up.q2;
    st[v].q3 += up.q3;
    return;
  }
  int mid = ( tl + tr) / 2;
  update(v * 2, tl, mid, l, min(r, mid), up);
  update(v * 2 + 1, mid + 1, tr, max(mid + 1, l), r, up);
  return;
}
tnode find(int v, int tl, int tr, int idx)
{
  if(tl == tr)
  {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  tnode r;
  if(idx <= tm)
  {
     r = find(v * 2, tl, tm, idx);
  }
  else
  {
     r = find(v * 2 + 1, tm + 1, tr, idx);
  }
  return combine(r, st[v]);
}
int main()
{

  int n;
  scanf("%d", &n);
  for(int x = 0;x < n;x++)
  {
    scanf("%d", &ar[x]);
    undo[x].q1 = 0;
    undo[x].q2 = 0;
    undo[x].q3 = 0;
  }
  int m;
  scanf("%d", &m);
  while(m--)
  {
    int type;
    scanf("%d", &type);
    if(type == 1)
    {
      int l, r, p;
      scanf("%d %d %d", &l, &r, &p);
      l--;
      r--;
      int q1 = 0, q2 = 0, q3 = 0;
      switch (p) {
        case 2:
        q1 = 1;
        break;
        case 3:
        q2 = 1;
        break;
        case 5:
        q3 = 1;
        break;
      }
      tnode up = (tnode){q1, q2, q3};
      update(1, 0, n - 1, l, r, up);
    }
    else
    {
      int l, d;
      scanf("%d %d", &l, &d);
      l--;
      tnode u = find(1, 0, n - 1, l);
      undo[l].q1 = u.q1;
      undo[l].q2 = u.q2;
      undo[l].q3 = u.q3;
      ar[l] = d;
    }
  }
  for(int x = 0;x < n;x++)
  {
    tnode u = find(1, 0, n - 1, x);
    u.q1 -= undo[x].q1;
    u.q2 -= undo[x].q2;
    u.q3 -= undo[x].q3;
    int val = ar[x];
    while((ar[x] > 1) && ((ar[x] % 2 )== 0))
      ar[x] %= 2;
    while((ar[x] > 1) && ((ar[x] % 3 )== 0))
      ar[x] %= 3;
    while((ar[x] > 1) && ((ar[x] % 5 )== 0))
      ar[x] %= 5;
    cout<<ar[x]<<" ";

  }
  cout<<endl;

  return 0;
}
