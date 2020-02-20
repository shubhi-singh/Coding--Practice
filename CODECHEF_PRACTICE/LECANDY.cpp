#include <iostream>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n, c;
    scanf("%d %d", &n, &c);
    int sum = 0;
    while(n--)
    {
      int num;
      sum += (scanf("%d", &num), num);
    }
    if(sum <= c)
      cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
  }
  return 0;
}
