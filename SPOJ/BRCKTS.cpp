#include<bits/stdc++.h>
#define NMAX 30000
using namespace std;
struct node
{
  int ob;
  int cb;
};
node t[4 * NMAX];
node combine(node a, node b)
{
  int rem = min(a.ob, b.cb);
  return (node){a.ob - rem + b.ob, b.cb - rem + a.cb};
}
void build(int ar[][2], int v, int tl, int tr)
{
  //cout<<tl<<" "<<tr<<endl;
  if(tl == tr)
  {
    t[v] = (node){ar[tl][0], ar[tl][1]};
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(ar, v * 2, tl, tm);
    build(ar, v * 2 + 1, tm + 1, tr);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);

  }
  //cout<<"HEY "<<t[v].ob<<" "<<t[v].cb<<endl;
}
void update(int v, int tl,int tr, int pos)
{
  if(tl == tr)
  {
    int a = t[v].ob;
    t[v].ob = t[v].cb;
    t[v].cb = a;
  }
  else
  {
    int tm = (tl + tr) / 2;
    if(pos <= tm)
      update(v * 2,tl , tm, pos);
    else
      update(v * 2 + 1, tm + 1, tr, pos);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
  }
}
int main()
{
  for(int x = 1;x <= 10;x++)
  {
    int n;
    scanf("%d", &n);
    string br;
    cin>>br;
    int ar[NMAX][2];
    for(int y = 0;y < n;y++)
    {
      if(br[y] == '(')
      {
        ar[y][0] = 1;
        ar[y][1] = 0;
      }
      else
      {
        ar[y][0] = 0;
        ar[y][1] = 1;
      }
      //cout<<"HEY@ "<<ar[y][0]<<" "<<ar[y][1]<<endl;
    }
    build(ar, 1, 0, n - 1);
    int m;
    scanf("%d", &m);
    int q[1000009];
    for(int y = 0;y < m;y++)
    {
      scanf("%d", &q[y]);
    }
    cout<<"Test "<<x<<":"<<endl;
    for(int y = 0;y < m;y++)
    {
      int k = q[y];
      if(k == 0)
      {
        string ans;
        //cout<<t[1].ob<<" "<<t[1].cb<<endl;
        if(t[1].ob == 0 && t[1].cb == 0)
          ans = "YES";
        else
         ans = "NO";
        cout<<ans<<endl;
      }
      else
      {
        update(1, 0,n - 1, k - 1);
      }
    }
  }
  return 0;
}
