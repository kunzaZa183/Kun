#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int x;
    cin >> x;
    int cur = x;
    vector<int> ans(1, cur);
    int maxi = 0;
    for (int i = 0; i < 31; i++)
      if (cur & (1 << i))
      {
        cur -= (1 << i);
        ans.push_back(cur);
        maxi = i;
      }
    ans.pop_back();
    ans.pop_back();
    cur += (1 << maxi);
    ans.push_back(cur);
    while (cur != 1)
    {
      cur /= 2;
      ans.push_back(cur);
    }
    cout << ans.size() << "\n";
    for (auto a : ans)
      cout << a << ' ';
    cout << "\n";
  }
}