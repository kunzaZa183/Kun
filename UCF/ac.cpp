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
    string s;
    cin >> s;
    vector<int> cs(n, 0);
    int last = 0;
    for (int i = n - 1; i >= 0; i--)
      if (s[i] == 'C')
        cs[i] = ++last;
      else
        cs[i] = last;
    int count = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == 'A')
        count += cs[i];
    cout << count << '\n';
  }
}