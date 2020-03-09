#include <bits/stdc++.h>
using namespace std;
int findChar(int prev, int nxt, int k)
{
  int s = 0;
  for(int x = 0;x < k;x++)
  {
    if(x != prev && x != nxt)
      return x;
  }
  return -1;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int k;

    scanf("%d", &k);
    string s;
    cin>>s;
    string ans = s;
    int l = s.length();
    if(l == 1)
    {
      ans = (s[0] == '?' )? "0": s;
      cout<<ans<<endl;
      continue;
    }
    else
    {
      for(int x = 0;x < l;x++)
      {
        if(s[x] == '?')
          continue;
        if(x == 0)
        {
          if((s[0] == s[l - 1] )|| (s[0] == s[1]))
            {
              ans = "NO";
              break;
            }
        }
        else if(x == (l - 1))
        {
          if((s[0] == s[l - 1] )|| (s[l - 1] == s[l - 2]))
            {
              ans = "NO";
              break;
            }
        }
        else
        {
          if((s[x] == s[x + 1]) || (s[x] == s[x - 1]))
          {
            ans = "NO";
            break;
          }
        }
      }
      if(ans.compare("NO") != 0)
      {
    int x;
    for( x = 0;x < l;x++)
    {
      if(s[x] == '?')
      {
      int prev, nxt;
      if(x == 0)
      {
        prev = (s[l - 1]- 48);
        nxt = (s[1] - 48);
      }
      else if(x == (l - 1))
      {
        prev = (s[l - 2] - 48);
        nxt = (s[0] - 48);
      }
      else
      {
        prev = (s[x - 1] - 48);
        nxt = (s[x + 1] - 48);
      }

      int c = findChar(prev, nxt, k);
      if(c == -1)
        {
          ans = "NO";
          break;
        }
      else
      {
        s[x] =(char) (c + 48);
      }
    }
  }
}


  }
  ans = (ans.compare("NO") == 0 ? ans : s);
  cout<<ans<<endl;
  }
  return 0;
}
