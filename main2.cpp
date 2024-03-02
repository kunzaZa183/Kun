#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 301, MOD = 1e9 + 7, height = 9;
int arr[maxn], dp[maxn][maxn][height];
int diff, k;
int recur(int l, int r, int cur)
{
  if (l == r)
    return 0;
  if (cur == k - 1)
    return 1;
  if (dp[l][r][cur] == -1)
  {
    // can be 0
    int curl = 0;
    int curr = accumulate(arr + l, arr + r, 0ll);
    dp[l][r][cur] = 0;
    if (abs(curl - curr) <= diff)
    {
      dp[l][r][cur] += recur(l, l, cur + 1) * recur(l, r, cur + 1) % MOD;
      dp[l][r][cur] %= MOD;
    }
    for (int i = l; i < r; i++)
    {
      curl += arr[i];
      curr -= arr[i];
      if (abs(curl - curr) <= diff)
      {
        dp[l][r][cur] += recur(l, i + 1, cur + 1) * recur(i + 1, r, cur + 1) % MOD;
        dp[l][r][cur] %= MOD;
      }
    }
  }
  return dp[l][r][cur];
}
signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n >> k >> diff;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  memset(dp, -1, sizeof dp);
  cout << recur(0, n, 0) << "\n";
}