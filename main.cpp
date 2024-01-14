#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
tuple<int, int, int> tiii[maxn];
int lefty[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);
  int n, t;
  cin >> n >> t;
  string corr;
  cin >> corr;
  for (int i = 0; i < t; i++)
  {
    auto &[a, b, c] = tiii[i];
    cin >> a >> b >> c;
    b--, c--;
  }
  sort(tiii, tiii + t);
  int mini = INT_MAX, maxi = INT_MIN, ct = 0;
  for (int i = 0; i < n; i++)
  {
    bool works = 0;
    for (int tmpk = 0; tmpk <= n + 1; tmpk++)
    {
      string s(n, '0');
      memset(lefty, 0, sizeof lefty);
      lefty[i] = tmpk;
      s[i] = '1';
      for (int j = 0; j < t; j++)
      {
        auto [a, b, c] = tiii[j];
        if (lefty[b] > 0 || lefty[c] > 0)
        {
          if (s[b] == '1' && s[c] == '1')
          {
            lefty[b]--;
            lefty[c]--;
          }
          else if (s[b] == '1')
          {
            s[c] = '1';
            lefty[c] = tmpk;
            lefty[b]--;
          }
          else if (s[c] == '1')
          {
            s[b] = '1';
            lefty[b] = tmpk;
            lefty[c]--;
          }
        }
      }
      if (s == corr)
      {
        works = 1;
        mini = min(mini, tmpk);
        maxi = max(maxi, tmpk);
      }
    }
    ct += works;
  }
  cout << ct << ' ' << mini << " ";
  if (maxi == n + 1)
    cout << "Infinity\n";
  else
    cout << maxi << "\n";
}