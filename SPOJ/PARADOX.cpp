#include <iostream>
#include <cstring>
using namespace std;
int visited[110];
int recStack[110];
int adj[110];
int arg[110];

void solve(int n, string *ans)
{
  int v = adj[n];
  int color = arg[v];
  if(visited[n] == 0)
    color = 1 - color;
  if(visited[v] == -1)
  {
    visited[v] = color;
    recStack[v] = color;
    solve(v, ans);
  }
  else
  {
    if(recStack[v] != -1)
    {
      if(visited[v] != color)
        {
          *ans = "PARADOX";
          return;
        }
    }
  }
  recStack[n] = -1;
  return;
}
int main()
{
  int n;
  while(scanf("%d", &n), n != 0)
  {

    memset(visited, -1, (n + 1) * sizeof(int));
    memset(recStack, - 1, (n + 1) * sizeof(int));
    string ans = "NOT PARADOX";
    for(int x = 0;x < n;x++)
    {
      string color;
      cin>>adj[x + 1]>>color;
      //cout<<adj[x + 1]<<color;
      if(color.compare("false") != 0)
        arg[x + 1] = 1;
      else arg[x + 1] = 0;
    }
    int x;
    for(x = 1;x <= n && !(ans.compare("PARADOX") == 0);x++)
    {
      if(visited[x] == -1)
      {
        visited[x] = 1;
        recStack[x] = 1;
        solve(x, &ans);
        recStack[x] = -1;
      }
    }
    //cout<<x<<endl;
    cout<<ans<<endl;
  }
  return 0;
}
