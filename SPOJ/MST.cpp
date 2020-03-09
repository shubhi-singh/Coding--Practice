#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> parent;
vector<int> sz;
struct Edge{
  int u, v, w;
};
bool compare(Edge a, Edge b)
{
  return a.w < b.w;
}
int find_set(int v)
{
  while(v != parent[v])
    v = parent[v];
  return v;
}
void make_set(int v)
{
  parent[v] = v;
  sz[v] = 1;
  return;
}
void union_sets(int a, int b)
{
  a = find_set(a);
  b = find_set(b);
  if(a != b)
  {
    if(sz[a] < sz[b])
      swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  parent.resize(n + 1);
  sz.resize(n + 1);
  vector<Edge> ar;
  ll ans = 0;
  for(int x = 0;x < m;x++)
  {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    ar.push_back((Edge){u, v, w});
  }
    sort(ar.begin(), ar.end(), compare);
    for(int x = 1;x <= n;x++)
      make_set(x);
    for(int x = 0;x < m;x++)
    {
      int pu = find_set(ar[x].u);
      int pv = find_set(ar[x].v);
      if(pu == pv)
        continue;
      ans += ar[x].w;
      union_sets(pu, pv);
    }
    cout<<ans<<endl;
  return 0;
}
