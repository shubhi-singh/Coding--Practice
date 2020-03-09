#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
vector<vector<int>> g;
vector<bool> visited;
vector<int> order;
vector<ll> dp;
void dfs(int u)
{
  visited[u] = true;
  for(int v : g[u])
  {
    if(!visited[v])
      dfs(v);
  }
  order.push_back(u);
}
int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    int p, q;
    scanf("%d %d", &p, &q);
    g.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    dp.assign(n + 1, -1);
    for(int x = 0;x < m;x++)
    {
      int a, b;
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
    }
    order.clear();
    for(int x = 1;x <= n;x++)
    {
      if(!visited[x])
      {
        dfs(x);
      }
    }
    /*
    for(int x = 0;x < n;x++)
      cout<<order[x]<<endl;
      */
    int pidx, qidx;

    for(int x = 0;x < n;x++)
    {
      if(order[x] == p)
        pidx = x;
      else if(order[x] == q)
        qidx = x;
    }
    //cout<<pidx<<" "<<qidx<<endl;
    dp[q] = 1;
    for(int x = qidx + 1;x <= pidx;x++)
    {
      int u = order[x];
      dp[u] = 0;
      for(int y = 0;y < g[u].size();y++)
      {
        int v = g[u][y];
        if(dp[v] == -1)
          continue;
        dp[u] = (dp[u] % MOD +  dp[v] % MOD)%MOD;
      }
    }
    cout<<dp[p]<<endl;

  return 0;

}
