#include <bits/stdc++.h>
using namespace std;
/*struct StNode
{
  int sum;
  void assignLeaf(int value)
  {
    sum = value;
  }
  void merge(StNode &left, StNode &right)
  {
    sum  = left.sum + right.sum;
  }
  int getValue()
  {
    return sum;
  }
};
template<class T, class V>
class St
{
  StNode* nodes;
  int n;
  public:
  St(T arr[], int n)
  {
    this->n = n;
    nodes = new StNode[getStSize(n)];
    buildTree(arr, 1, 0, n - 1);
  }
  V getValue(int lo, int hi)
  {
    StNode result = getValue(1, 0, n - 1, lo, hi);
    return result.getValue();
  }
  void update(int idx, T value)
  {
    update(1, 0, n - 1, idx, value);
  }
  private:
  void buildTree(T arr[], int stIdx, int lo, int hi)
  {
    if(lo == hi)
    {
      nodes[stIdx].assignLeaf(arr[lo]);
      return;
    }
    int left = 2 * stIdx, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIdx].merge(nodes[left], nodes[right]);

  }
  StNode getValue(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];

    int mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);

    StNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    StNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    StNode result;
    result.merge(leftResult, rightResult);
    return result;
  }

  int getStSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }

  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }

    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);

    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};
*/
struct score
{
  int a;
  int b;
  int id;
};
bool compare1(score s1, score s2)
{
  if(s1.a > s2.a)
    return true;
  else if(s1.a == s2.a && s1.b > s2.b)
    return true;
  return false;
}
bool compare2(score s1, score s2)
{
  if(s1.b > s2.b)
    return true;
  else if(s1.b == s2.b && s1.a > s2.a)
    return true;
  return false;
}
int main()
{
  int n;
  scanf("%d", &n);
  vector<score> ar;
  for(int x = 0;x < n;x++)
  {
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    ar.push_back((score){s1, s2, x});
  }
  sort(ar.begin(), ar.end(), compare1);
  vector<score> ar2 = ar;
  sort(ar2.begin(), ar2.end(), compare2);
  vector<int> pos(n);
  for(int x = 0;x < n;x++)
  {
    int id = ar2[x].id;
    pos[id] = x;
  }
  int ar
  St segTree = new St<int, int>()
  for(int x = 0;x < n;x++)
  {
    int id = ar[x].id;
    int p = pos[id];
    int ans = 0;
    if(p == (n - 1))
      ans = 0;
    else
      ans = getSum(p + 1, n - 1);
    update()
    cout<<ans;

  }
  return 0;
}
