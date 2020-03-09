#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> ar;
    int sum = 0;
    for(int x = 0;x < n;x++)
      {
        int w;
        scanf("%d", &w);
        ar.push_back(w);
        sum += w;
      }
    sort(ar.begin(), ar.end());
    k = min(k, n - k);
    int kSum = 0;
    for(int x = 0;x < k;x++)
      kSum += ar[x];
    cout<<(sum - kSum - kSum)<<endl;

  }
  return 0;
}
