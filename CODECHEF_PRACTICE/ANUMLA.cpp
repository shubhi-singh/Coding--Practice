#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    int ar[40000];
    int sz = pow(2, n);
    for(int x = 0;x < sz;x++)
      scanf("%d", &ar[x]);
    sort(ar, ar + sz);
    int idx = 1;
    int count = 0;
    while(count < n)
    {
      cout<<ar[idx]<<" ";
      idx *= 2;
      count++;
    }
    cout<<endl;
  }
  return 0;
}
