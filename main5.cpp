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
    vector<pair<int, int>> vpii;
    int cur = 1;
    while (1)
    {
      int cur2 = cur + k;
      cur2--;
      if (cur2 > m)
        cur2 = m;
      vpii.emplace_back(cur, cur2);
      if (cur2 == m)
        break;
      cur = cur2 + 1;
    }
    for (auto a : vpii)
    {
      // cout << a.first << " " << a.second << "\n";
      deque<int> dqi;
      dqi.push_back(a.first);
      int low = a.first + 1, high = a.second;
      int ct = 0;
      while (1)
      {
        if (low >= high)
          break;
        if (ct % 2 == 0)
        {
          dqi.push_front(low);
          dqi.push_back(high);
          low++;
          high--;
        }
        else
        {
          dqi.push_front(high);
          dqi.push_back(low);
          low++;
          high--;
        }
        ct++;
      }
      if (low == high)
        dqi.push_back(low);
      for (auto a : dqi)
        cout << a << " ";
    }
    cout << "\n"
         << vpii.size() << '\n';
    for (int j = 0; j < vpii.size(); j++)
    {
      for (int i = vpii[j].first; i <= vpii[j].second; i++)
        cout << j + 1 << " ";
    }
    cout << "\n";
  }
}