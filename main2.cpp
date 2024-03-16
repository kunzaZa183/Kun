#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int m, k;
    cin >> m >> k;
    vector<tuple<int, int, int>> vpii;
    int cur = k;
    while (1)
    {
      int curl = cur - k + 1;
      int curr = cur + k - 2;
      // cout << curl << " " << cur << " " << curr << "\n";
      if(curr<cur)
        curr = cur;
      if (cur >= m)
        cur = m;
      if (curr >= m)
        curr = m;
      vpii.emplace_back(curl, cur, curr);
      if (curr == m)
        break;
      cur = curr + k;
    }
    for (auto [curl, cur, curr] : vpii)
    {
      for (int i = cur - 1; i >= curl; i--)
        cout << i << " ";
      cout << cur << " ";
      for (int i = curr; i > cur; i--)
        cout << i << " ";
    }
    cout << "\n"
         << vpii.size() << '\n';
    for (int j = 0; j < vpii.size(); j++)
    {
      auto [curl, cur, curr] = vpii[j];
      for (int i = cur - 1; i >= curl; i--)
        cout << j + 1 << " ";
      cout << j + 1 << " ";
      for (int i = curr; i > cur; i--)
        cout << j + 1 << " ";
    }
    cout << "\n";
  }
}