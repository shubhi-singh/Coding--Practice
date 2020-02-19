#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    int ar[110];
    for(int x = 0;x < n;x++)
      scanf("%d", &ar[x]);
    sort(ar, ar + n);
    int prev = ar[0];
    ll extra = 0;
    for(int x = 1;x < n;x++)
    {
      ar[x] += extra;
      extra += (ar[x] - prev);
      prev = ar[x];
    }
    cout<<extra<<endl;

  }
  return 0;
}
