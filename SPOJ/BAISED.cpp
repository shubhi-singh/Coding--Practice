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
    vector<int> ar;
    ll ans = 0;
    for(int x = 0;x < n;x++)
    {
      string s;
      int pos;
      cin>>s>>pos;
      ar.push_back(pos);
    }
    sort(ar.begin(), ar.end());
    for(int x = 1;x <= n;x++)
      ans += abs(ar[x - 1] - x);
    cout<<ans<<endl;
  }
  return 0;
}
