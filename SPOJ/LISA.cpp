#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    string s;
    cin>>s;
    int l = s.length();
    vector<int> num;
    vector<char> op;
    for(int x = 0;x < l;x++)
      {
        char c = s[x];
        if(c >= '0' && c <= '9')
          num.push_back(c - 48);
        else op.push_back(c);
      }
    int n = num.size();
    vector<vector<ll>> maxVal(n, vector<ll>(n));
    vector<vector<ll>> minVal(n, vector<ll>(n));
    for(int x = 0;x < n;x++)
      {
        maxVal[x][x] = num[x];
        minVal[x][x] = num[x];
      }
    for(int x = 2;x <= n;x++)
    {
      for(int y = 0;y <= (n - x);y++)
      {
        int rl = y + x - 1;
        maxVal[y][rl] = LLONG_MIN;
        minVal[y][rl] = LLONG_MAX;
        for(int z = y;z < (rl);z++)
        {
          switch(op[z])
          {
            case '+':
            maxVal[y][rl] = max(maxVal[y][rl], maxVal[y][z] + maxVal[z + 1][rl]);
            minVal[y][rl] = min(minVal[y][rl], minVal[y][z] + minVal[z + 1][rl]);
            break;
            case '*':
            maxVal[y][rl] = max(maxVal[y][rl], maxVal[y][z] * maxVal[z + 1][rl]);
            minVal[y][rl] = min(minVal[y][rl], minVal[y][z] * minVal[z + 1][rl]);
            break;
          }
        }
      }
    }
    cout<<maxVal[0][n - 1]<<" "<<minVal[0][n - 1]<<endl;
  }
  return 0;
}
