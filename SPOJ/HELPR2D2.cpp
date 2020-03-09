#include <bits/stdc++.h>
#define ll long long int
#define NMAX 1000000
using namespace std;
int t[4 * NMAX];
int k;
int ans = 0;
int combine(int a, int b)
{
  return max(a, b);
}
void build(int v, int tl, int tr, int ar[])
{
  if(tl == tr)
  {
    t[v] = k;
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, ar);
    build(v * 2 + 1, tm + 1, tr, ar);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
  }
}
void update(int v, int tl, int tr, int vol)
{
  if(tl == tr)
  {
    if(t[v] == k)
      ans++;
    t[v] -= vol;
  }
  else
  {
    int tm = (tl + tr) / 2;
    if(vol <= t[v * 2])
    {
      update(v * 2, tl, tm, vol);
    }
    else
    {
      update(v * 2 + 1, tm + 1, tr, vol);
    }
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d %d", &k, &n);
    int count = 0;
    ans = 0;
    ll sum = 0;
    int ar[NMAX];
    for(int x = 0;x < n;x++)
      ar[x] = k;
    build(1, 0,n - 1, ar);
    while(count < n)
    {
      int r = 0;
      int v;
      char ip;
      cin>>ip;
      if(ip == 'b')
      {
        cin>>r>>v;
        //cout<<r<<v<<endl;
      }
      else
      {
        v = (ip - 48);
        char c;
        scanf("%c", &c);
        while(c != '\n')
        {
          v = v * 10 + (c - 48);
          scanf("%c", &c);
        }
        //cout<<v<<endl;
      }
      if(r == 0)
      {
        update(1, 0, n - 1, v);
        count++;
        sum += v;
      }
      else
      {
      for(int x = 0;x < r;x++)
      {
        update(1, 0, n - 1 ,v);
        count++;
        sum += v;
      }
    }
    }
    cout<<ans<<" "<<((ll)ans) * k-sum<<endl;
  }
  return 0;
}
