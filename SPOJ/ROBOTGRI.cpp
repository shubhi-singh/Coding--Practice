#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool inLimits(int x, int y, int n)
{
  if(!(x >= 0 && x < n && y >= 0 && y < n))
    return false;
  return true;
}
ll dp[1010][1010];
bool visited[1010][1010];
int main()
{
  int n;
  scanf("%d", &n);
  scanf("%*c");
  int ar[1010][1010];
  for(int x = 0;x < n;x++)
  {
    for(int y = 0;y < n;y++)
    {
      char c;
      scanf("%c", &c);
      if(c == '.')
        ar[x][y] = 1;
      else if(c == '#')
      ar[x][y] = 0;
      else
      ar[x][y] = -1;
    }
    scanf("%*c");
  }
  /*
  for(int x = 0;x < n;x++)
  {
    for(int y = 0;y < n;y++)
    {
      cout<<ar[x][y]<<" ";
    }
    cout<<endl;
  }
  */

  ll MOD = ((ll)1<<31) - 1;
  dp[0][0] = 1;
  int ans = 0;
  int dirs1[][2] = {{0, -1}, {-1, 0}};
  for(int x = 0;x < n;x++)
  {
    for(int y = 0;y < n;y++)
    {
       if((x == 0 && y == 0))
        continue;
      dp[x][y] = 0;
      if(ar[x][y] == 0)
        continue;
      for(int d = 0;d < 2;d++)
      {
        int nx = x + dirs1[d][0];
        int ny = y + dirs1[d][1];
        if(!inLimits(nx, ny, n))
          continue;
        dp[x][y] =(dp[x][y] % MOD +  dp[nx][ny] % MOD) % MOD;
      }
    }
  }
  if(dp[n - 1][n - 1] != 0)
    {
      cout<<dp[n - 1][n - 1]<<endl;
      return 0;
    }
  string rep = "INCONCEIVABLE";
  queue<int> bfs;
  memset(visited, false, sizeof(bool) * n * n);
  visited[0][0] = true;
  bfs.push(0);
  int target = n * n - 1;
  int dirs2[][4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  while(!bfs.empty())
  {
    int node = bfs.front();
    bfs.pop();
    if(node == target)
    {
      rep = "THE GAME IS A LIE";
      break;
    }
    int r = node / n;
    int c = node % n;
    for(int x = 0;x < 4;x++)
    {
      int nr = r + dirs2[x][0];
      int nc = c + dirs2[x][1];
      if(!inLimits(nr, nc, n))
        continue;
      if(ar[nr][nc] == 0 || visited[nr][nc])
        continue;
      visited[nr][nc] = true;
      bfs.push(nr * n + nc);
    }
  }
  cout<<rep<<endl;
  return 0;
}
