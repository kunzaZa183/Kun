#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n;
    vector<int> vi(n);
    for (auto &a : vi)
      cin >> a;
    sort(vi.begin(), vi.end(), greater<int>());
    int sum = 0, last = INT_MAX;
    for (auto a : vi)
      if (last - a >= 2)
      {
        sum += a;
        last = a;
      }
    cout << sum << '\n';
  }
}