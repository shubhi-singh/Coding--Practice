#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long int
using namespace std;
pii ar[10010];
bool compared(pii a, pii b)
{
  return a.first > b.first;
}
struct comparef
{

  bool operator()(pii a, pii b)
  {
  return a.second < b.second;
}
};
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    for(int x = 0;x < n;x++)
    {
      scanf("%d %d", &ar[x].first, &ar[x].second);
    }
    sort(ar, ar + n, compared);
    priority_queue<pii, vector<pii>, comparef> pq;
    ll d;
    ll f;
    scanf("%lld %lld", &d, &f);
    int i = 0;
    int stops = 0;
    while(f < d)
    {
      ll dist = d - f;
      while(i < n && ar[i].first >= dist)
      {
        pq.push(ar[i]);
        i++;
      }
      pii stop;
      bool flag = false;
      while(!pq.empty())
      {
        if(pq.top().first < d && pq.top().first >= dist)
        {
          stop = pq.top();
          pq.pop();
          flag = true;
          break;
        }
        pq.pop();
      }
      if(!flag)
        break;
      stops++;
      f = f - (d - stop.first) + stop.second;
      d = stop.first;
      //cout<<stop.first<<" "<<stop.second;

    }
    if(f < d)
      cout<<-1<<endl;
    else
    cout<<stops<<endl;



  }
  return 0;
}
