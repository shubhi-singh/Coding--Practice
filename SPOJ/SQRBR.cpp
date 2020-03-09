#include <bits/stdc++.h>
using namespace std;
int solve(int idx, int open, int av, vector<bool> &ar, int dp[40][20][20])
{
  if(dp[idx][open][av] != -1)
    return dp[idx][open][av];
  int ans = 0;
  if(ar[idx])
  {
    ans = solve(idx + 1, open + 1, av, ar, dp);
  }
  else
  {
    if(av > 0)
    {
      ans = solve(idx + 1, open + 1, av - 1, ar, dp);
    }
    if(open > 0)
    {
      ans += solve(idx + 1, open - 1, av, ar, dp);
    }
  }
  dp[idx][open][av] = ans;
  return ans;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<bool> ar(2*n + 1, false);
    for(int x = 0;x < k;x++)
    {
      int val;
      scanf("%d", &val);
      ar[val] = true;
    }
    int dp[40][20][20];
    memset(dp, -1, sizeof dp);
    dp[2 * n + 1][0][0] = 1;
    cout<<solve(1, 0, n - k, ar, dp)<<endl;
  }
}
