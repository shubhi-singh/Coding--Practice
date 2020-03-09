#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct trainer
{
  ll d;
  ll t;
  ll s;
};
struct compares
{
bool operator()(trainer const &a, trainer const &b)
{
  return a.s < b.s;
}
};
bool compared(trainer a, trainer b)
{
  return a.d < b.t;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n, d;
    scanf("%d %d", &n, &d);
    trainer trainers[100010];
    for(int x = 0;x < n;x++)
      scanf("%lld %lld %lld", &trainers[x].d, &trainers[x].t, &trainers[x].s);
    sort(trainers, trainers + n, compared);
    int i = 0;
    priority_queue<trainer, vector<trainer>, compares> pq;
    ll ans = 0;
    for(int x = 1;x <= d;x++)
    {
      while(i < n && trainers[i].d == x)
      {
        pq.push(trainers[i]);
        i++;
      }
      if(pq.empty())
        continue;
      trainer t = pq.top();
      pq.pop();
      if(t.t != 1)
      {
        pq.push({t.d, t.t - 1, t.s});
      }

    }
    while(!pq.empty())
    {
      trainer t = pq.top();
      pq.pop();
      ans += t.t * t.s;
    }
    cout<<ans<<endl;

  }
  return 0;
}
