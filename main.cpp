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
    int y = n ^ m;
    if (y < n)
    {
      cout << "1\n";
      cout << n << ' ' << m << "\n";
    }
    else
      cout << "-1\n";
  }
}