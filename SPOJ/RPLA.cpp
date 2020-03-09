#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;
vector<vector<int>> g;
vector<int> visited;
vector<int> order;
bool compare(pii a, pii b)
{
  if((a.first < b.first) || (a.first == b.first && a.second < b.second))
    return true;
  return false;

}
void dfs(int u)
{
  visited[u] = 1;
  for(int v : g[u])
  {
    if(visited[v] == -1)
      dfs(v);
  }
  order.push_back(u);
}
void dfs2(int u)
{
  for(int v : g[u])
  {
    if(visited[v] == -1)
      {
        visited[v] = visited[u]  + 1;
        dfs2(v);
      }
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  for(int y = 1;y <= t;y++)
  {
    int n, r;
    scanf("%d %d", &n, &r);
    g.assign(n, vector<int>());
    visited.assign(n, -1);
    order.clear();
    for(int x = 0;x < r;x++)
    {
      int r1, r2;
      scanf("%d %d", &r1, &r2);
      g[r1].push_back(r2);
    }
    for(int x = 0;x < n;x++)
    {
      if(visited[x] == -1)
      {
        dfs(x);
      }
    }
    //reverse(order.begin(), order.end());

    vector<int>  rank(n, 1);
    for(int x = 0;x < n;x++)
    {
      int u = order[x];
      //cout<<"HEY "<<u<<endl;
      rank[u] = 1;
      for(int v : g[u])
      {
        //cout<<u<<" "<<v<<endl;
        rank[u] = max(rank[u], 1 + rank[v]);
      }
    }

    vector<pii> ans;
    for(int x = 0;x < n;x++)
    {
      ans.push_back({rank[x], x});
    }
    sort(ans.begin(), ans.end(), compare);
    cout<<"Scenario #"<<y<<":"<<endl;
    for(int x = 0;x < n;x++)
      cout<<ans[x].first<<" "<<ans[x].second<<endl;
    
  }
  return 0;
}
