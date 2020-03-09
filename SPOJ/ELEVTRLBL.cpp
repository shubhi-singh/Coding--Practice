#include <bits/stdc++.h>
using namespace std;
int visited[1000010];
int main()
{
  int f, s, g, u, d;
  int ans = -1;
  scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
  memset(visited, -1, sizeof(int) * (f + 1));
  int dirs[] = {u, d * -1};
  queue<int> bfs;
  bfs.push(s);
  visited[s] = 0;
  while(!bfs.empty())
  {
    int floor = bfs.front();
    bfs.pop();
    if(floor == g)
      {
        ans = visited[floor];
        break;
      }
    for(int x = 0;x < 2;x++)
    {
      int target = floor + dirs[x];
      if(!(target >= 1 && target <= f))
        continue;
      if(visited[target] != -1)
        continue;
      visited[target] = visited[floor] + 1;
      bfs.push(target);
    }
  }
  if(ans != -1)
    cout<<ans<<endl;
  else
    cout<<"use the stairs"<<endl;


  return 0;
}
