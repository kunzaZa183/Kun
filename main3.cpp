#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000, BIGNUM = 1e9 + 1;
int type[maxn], weight[maxn], qsum[maxn];
vector<int> all[maxn + 1];
int dp[maxn][2];
int n;
int sumright(int a, int b)
{
  if (a < b)
  {
    if (a == 0)
      return qsum[b - 1];
    return qsum[b - 1] - qsum[a - 1];
  }
  if (a == b)
    return 0;
  int front;
  if (b == 0)
    front = 0;
  else
    front = qsum[b - 1];
  int back = qsum[n - 1] - qsum[a - 1];
  return back + front;
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  int maxtype = -1;
  for (int i = 0; i < n; i++)
    cin >> type[i];
  for (int i = 0; i < n; i++)
    cin >> weight[i];
  qsum[0] = weight[0];
  for (int i = 1; i < n; i++)
    qsum[i] = qsum[i - 1] + weight[i];
  for (int i = 0; i < n; i++)
    maxtype = max(maxtype, type[i]);
  for (int i = 0; i < n; i++)
    all[type[i]].push_back(i);
  int in = 0;
  int sumall = accumulate(weight, weight + n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      dp[i][j] = BIGNUM;
  for (auto a : all[1])
    dp[a][0] = 0;
  for (int i = 1; i < maxtype; i++)
  {
    if (all[i].size() == 1)
      dp[all[i].front()][1] = dp[all[i].front()][0];
    else
    {
      for (auto a : all[i])
        for (auto b : all[i])
          if (a != b)
            dp[b][1] = min(dp[b][1], dp[a][0] + min(sumright(a, b), sumright(b, a)));
    }
    for (auto a : all[i])
      for (auto b : all[i + 1])
        dp[b][0] = min(dp[b][0], dp[a][1] + min(sumright(a, b), sumright(b, a)));
  }
  if (all[maxtype].size() == 1)
    dp[all[maxtype].front()][1] = dp[all[maxtype].front()][0];
  else
  {
    for (auto a : all[maxtype])
      for (auto b : all[maxtype])
        if (a != b)
          dp[b][1] = min(dp[b][1], dp[a][0] + min(sumright(a, b), sumright(b, a)));
  }
  int mini = INT_MAX;
  for (auto a : all[maxtype])
    mini = min(mini, dp[a][1]);
  cout << mini << '\n';
}