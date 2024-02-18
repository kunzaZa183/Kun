#include <bits/stdc++.h>
using namespace std;
#define int long long
struct element
{
  int time, inl, inr;
  friend bool operator<(element a, element b)
  {
    return a.time < b.time;
  }
  element(int a, int b, int c)
  {
    time = a, inl = b, inr = c;
  }
};
const int maxn = 200000;
multiset<element> mse;
int pos[maxn], speed[maxn], death[maxn];
int val(int inl, int inr)
{
  if (inl % 2 == 0)
    return (pos[inr] - pos[inl] + (speed[inl] + speed[inr] - 1)) / (speed[inl] + speed[inr]) * 2 - 1;
  return (pos[inr] - pos[inl] + (speed[inl] + speed[inr] - 1)) / (speed[inl] + speed[inr]) * 2;
}
signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> pos[i];
    for (int i = 0; i < n; i++)
      cin >> speed[i];
    set<int> si;
    for (int i = 0; i < n; i++)
      si.insert(i);
    mse.clear();
    for (int i = 0; i < n - 1; i++)
      mse.emplace(val(i, i + 1), i, i + 1);
    while (!mse.empty())
    {
      element tmp = *mse.begin();
      mse.erase(mse.begin());
      death[tmp.inl] = tmp.time, death[tmp.inr] = tmp.time;
      int left = -1, right = -1;
      if (tmp.inl != *si.begin())
      {
        auto it = si.find(tmp.inl);
        it--;
        mse.erase(element(val(*it, tmp.inl), *it, tmp.inl));
        left = *it;
      }
      if (tmp.inr != *si.rbegin())
      {
        auto it = si.find(tmp.inr);
        it++;
        mse.erase(element(val(tmp.inr, *it), tmp.inr, *it));
        right = *it;
      }
      si.erase(tmp.inl), si.erase(tmp.inr);
      if (left != -1 && right != -1)
        mse.emplace(val(left, right), left, right);
    }
    for (int i = 0; i < n; i++)
    {
      if (i != 0)
        cout << " ";
      cout << death[i];
    }
    cout << "\n";
  }
}