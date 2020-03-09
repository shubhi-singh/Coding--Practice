#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    int sum = 0;
    for(int x = 0;x < n;x++)
      {
        int  score;
        scanf("%d", &score);
        sum += score;
      }
    cout<<min(m,sum)<<endl;
  }
  return 0;
}
