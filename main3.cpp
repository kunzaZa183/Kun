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
      cout << a.first << " ";
      for (int i = a.second; i > a.first; i--)
        cout << i << " ";
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