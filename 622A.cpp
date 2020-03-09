#include <bits/stdc++.h>
using namespace std;
void sortNum(int ar[3])
{
  sort(ar, ar + 3);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int ar[3];
    int ans = 0;
    int a, b, c;
    scanf("%d %d %d", &ar[0], &ar[1], &ar[2]);
    if(ar[1] > 0)
    {
      ar[1]--;
      ans++;
    }
    if(ar[0] > 0)
    {
      ar[0]--;
      ans++;
    }
    if(ar[2] > 0)
    {
      ar[2]--;
      ans++;
    }
    sortNum(ar);
    if(ar[0] > 0 && ar[2] > 0)
    {
      ar[0]--;
      ar[2]--;
      ans++;
    }
    if(ar[1] > 0 && ar[2] > 0)
    {
      ar[1]--;
      ar[2]--;
      ans++;
    }
    if(ar[0] > 0 && ar[1] >  0)
    {
      ar[0]--;
      ar[1]--;
      ans++;
    }
    if(ar[1] > 0 && ar[0] > 0 && ar[2] > 0)
    {
      ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
