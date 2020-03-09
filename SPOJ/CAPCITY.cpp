#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g, gr;
vector<bool> visited;
vector<int> component;
vector<int> componentCount;
vector<int> order;
vector<int> sccorder;
vector<vector<int>>scc;
void dfs1(int u)
{
  visited[u] = true;
  for(int v : g[u])
    if(!visited[v])
      dfs1(v);
  order.push_back(u);
}
int dfs2(int u, int id)
{
  //cout<<"HEY "<<u<<endl;
  visited[u] = true;
  component[u] = id;
  int count = 1;
  for(int v : gr[u])
    if(!visited[v])
      count += dfs2(v, id);
  sccorder.push_back(u);
  return count;
}
int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    g.assign(n + 1, vector<int>());
    gr.assign(n + 1, vector<int>());
    for(int x = 0;x < m;x++)
    {
      int a, b;
      scanf("%d %d", &a, &b);
      g[b].push_back(a);
      gr[a].push_back(b);
    }
    visited.assign(n + 1, false);
    order.clear();
    for(int x = 1;x <= n;x++)
      if(!visited[x])
        dfs1(x);
    reverse(order.begin(), order.end());
    visited.assign(n + 1, false);
    component.assign(n + 1, 0);
    componentCount.clear();
    sccorder.clear();
    int comp = 0;
    /*
    for(int x = 0;x < n;x++)
      cout<<order[x]<<endl;
      */


    for(int x = 0;x < n;x++)
    {
      int u = order[x];
      if(!visited[u])
          {
            int count = dfs2(u, comp);
            componentCount.push_back(count);
            comp++;
          }
    }
    /*
    for(int x = 0;x < n;x++)
      cout<<sccorder[x]<<endl;
    for(int x = 1;x <= n;x++)
      cout<<"COMP "<<component[x]<<endl;
      */
    reverse(sccorder.begin(), sccorder.end());
    map<int, int> dp;
    int i = 0;
    for(int x = 0;x < n;)
    {
     int u = sccorder[x];
     int id = component[u];
     int ans = 0;
     int temp = i;
     while(i < n && component[sccorder[i]] == id)
     {
       int v = sccorder[i];
       dp[v] = componentCount[component[v]];
       for(int w : g[v])
       {
         if(component[w] != component[v])
          ans += dp[w];
       }
       i++;
     }
     for(int y = temp;y < i;y++)
      {
        int v = sccorder[y];
        dp[v] += ans;
        //cout<<"DP "<<v<<" "<<dp[v]<<endl;
      }


     x = i;
    }
    vector<int> ans;
    for(auto i : dp)
      if(i.second == (n))
        ans.push_back(i.first);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int x = 0;x < ans.size();x++)
     {
      cout<<ans[x]<<" ";
    }
    cout<<endl;




  return 0;
}
