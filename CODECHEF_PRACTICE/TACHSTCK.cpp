#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, d;
  int ans = 0;
  scanf("%d %d", &n, &d);
  int ar[100010];
  for(int x = 0;x < n;x++)
    scanf("%d", &ar[x]);
  sort(ar, ar + n);
  for(int x = 0;x < (n - 1);x++)
  {
    if((ar[x + 1] - ar[x]) <= d)
    {
      ans++;
      x++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
