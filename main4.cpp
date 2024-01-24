#include <bits/stdc++.h>
using namespace std;
const int maxn = 100, BIGNUM = 1000;
int dp[maxn][maxn][maxn], dp2[maxn][maxn][maxn];
int arr[maxn];
int x;
int two(int l, int r, int k);
int one(int l, int r, int k)
{
  if (dp[l][r][k] == BIGNUM)
  {
    int actuall = -1, actualr = -1;
    for (int i = l; i <= r; i++)
      if (arr[i] != k)
      {
        actuall = i;
        break;
      }
    for (int i = r; i >= l; i--)
      if (arr[i] != k)
      {
        actualr = i;
        break;
      }
    if (actuall == -1)
    {
      dp[l][r][k] = 0;
      return 0;
    }
    dp[l][r][k] = two(actuall, actualr, k) + 1;
    for (int i = actuall; i < actualr; i++)
      dp[l][r][k] = min(dp[l][r][k], one(actuall, i, k) + one(i + 1, actualr, k));
  }
  return dp[l][r][k];
}
int two(int l, int r, int k)
{
  if (dp2[l][r][k] == BIGNUM)
  {
    int actuall = -1, actualr = -1;
    for (int i = l; i <= r; i++)
      if (arr[i] == k)
      {
        actuall = i;
        break;
      }
    for (int i = r; i >= l; i--)
      if (arr[i] == k)
      {
        actualr = i;
        break;
      }
    if (actuall == -1)
    {
      dp2[l][r][k] = 0;
      return 0;
    }
    for (int i = 0; i < x; i++)
      if (i != k)
        dp2[l][r][k] = min(dp2[l][r][k], one(actuall, actualr, i));
    for (int i = actuall; i < actualr; i++)
      dp2[l][r][k] = min(dp2[l][r][k], two(actuall, i, k) + two(i + 1, actualr, k));
  }
  return dp2[l][r][k];
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      arr[i]--;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < x; k++)
          dp[i][j][k] = BIGNUM, dp2[i][j][k] = BIGNUM;
    int mini = BIGNUM;
    for (int i = 0; i < x; i++)
      mini = min(mini, one(0, n - 1, i));
    cout << mini << '\n';
  }
}