#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000000
using namespace std;
struct Edge{
  int dist;
  int u;
  int v;
};
bool compare(Edge a, Edge b)
{
  return a.dist > b.dist;
}
vector<int> parent, sz;
void make_set(int v)
{
  parent[v] = v;
  sz[v] = 1;
}
int find_set(int v)
{
  while(v != parent[v])
    v = parent[v];
  return v;
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
  vector<Edge> ar;
  ll ans = 0;
  ll sum = 0;
  for(int x = 0;x < m;x++)
  {
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    ar.push_back((Edge){w, u, v});
    sum += w;
  }
  sort(ar.begin(), ar.end(), compare);
  parent.resize(n + 1);
  sz.resize(n + 1);
  for(int x = 1;x <= n;x++)
    make_set(x);
  for(int x = 0;x < m;x++)
  {
    int pu = find_set(ar[x].u);
    int pv = find_set(ar[x].v);
    if(pu != pv)
    {
      ll comp = ((((ll)sz[pu]) % MOD) * (((ll)sz[pv]) % MOD)) % MOD;
      ans = (ans % MOD + ((comp % MOD) * (sum % MOD)) % MOD) % MOD;
      //ans = (ans % MOD + (sz[pu] * sz[pv] * sum) % MOD)%MOD;
      //ans += (sz[pu] * sz[pv] * sum);
      union_sets(pu, pv);
    }
    sum -= ar[x].dist;
  }
  cout<<ans<<endl;
  return 0;

}
