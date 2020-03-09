#include <bits/stdc++.h>
using namespace std;
bool isPrime[10000];
int main()
{
  memset(isPrime, true, sizeof isPrime);
  for(int i = 2; i <= sqrt(9999);i++)
  {
    if(isPrime[i])
    {
      for(int j = i * i;j <= 9999;j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  int t;
  scanf("%d", &t);
  while(t--)
  {
    int s, t;
    scanf("%d %d", &s, &t);
    map<string, int> visited;
    queue<string> bfs;
    string ss = to_string(s);
    string ts = to_string(t);
    visited[ss] = 0;
    bfs.push(ss);
    while(!bfs.empty())
    {
      string u = bfs.front();
      bfs.pop();
      if(u == ts)
        break;
      for(int x = 0;x < 4;x++)
      {
        char y = x == 0?'1' : '0';
        for(;y <= '9';y++)
        {
          if(y == u[x])
            continue;
          string cpy = u;
          cpy[x] = y;
          if(visited.find(cpy) != visited.end())
            continue;
          int v = stoi(cpy);
          if(!isPrime[v])
            continue;
          visited[cpy] = visited[u] + 1;
          bfs.push(cpy);
        }
      }
    }
    if(visited.find(ts) == visited.end())
      cout<<"Impossible";
    else
      cout<<visited[ts]<<endl;


  }
  return 0;
}
