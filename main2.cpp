#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> vi(n);
  for (auto &a : vi)
    cin >> a;
  while (q--)
  {
    int type, a, b;
    cin >> type >> a >> b;
    a--, b--;
    if (type == 1)
      for (int i = a; i <= b; i++)
        vi[i] += i - a + 1;
    else if (type == 2)
    {
      int sum = 0;
      for (int i = a; i <= b; i++)
        sum += vi[i];
      cout << sum << '\n';
    }
  }
}