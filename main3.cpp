#include <bits/stdc++.h>
using namespace std;
const int safe = 63;
#define int long long
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
    vector<int> vi;
    for (int i = 0; i < safe; i++)
      if ((1LL << i) & n)
        vi.push_back(i);
    vector<int> last;
    if (vi.size() == 1)
      for (int i = 0; i < vi.back(); i++)
        last.push_back(i);
    else
    {
      for (int i = 0; i < vi.size() - 1; i++)
        last.push_back(vi.back() - vi[i] - 1);
      for (int i = 0; i < vi.back(); i++)
        last.push_back(i);
    }
    cout << last.size() << "\n";
    for (auto a : last)
      cout << a << ' ';
    cout << '\n';
  }
}