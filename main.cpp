#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> vi, target;
    for (int i = 0; i < 63; i++)
      if ((1ll << i) & n)
        vi.push_back(i);
    for (int i = 0; i < 63; i++)
      if ((1ll << i) & m)
        target.push_back(i);
    if (vi.size() == 1)
    {
      cout << "-1\n";
      continue;
    }
    if (target.back() == vi.back())
    {
      if (target.size() == 1)
      {
        cout << "1\n"
             << n << " " << m << '\n';
      }
      else if (target[target.size() - 2] <= vi[vi.size() - 2])
      {
        cout << "1\n"
             << n << " " << m << '\n';
      }
      else
        cout << "-1\n";
    }
    else if (target.back() > vi[vi.size() - 2])
    {
      cout << "-1\n";
      continue;
    }
    else
    {
      int num = (1ll << (vi[vi.size() - 2] + 1));
      num--;
      if (num == m)
        cout << "1\n"
             << n << " " << m << "\n";
      else
      {
        cout << "2\n";
        cout << n << ' ' << num << ' ' << m << "\n";
      }
    }
  }
}