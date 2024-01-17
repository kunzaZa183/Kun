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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
      dp[all[i][0]][1] = dp[all[i][0]][0];
    else
    {
      for (int j = 1; j < all[i].size(); j++)
      {
        dp[all[i][j - 1]][1] = min(dp[all[i][j - 1]][1], sumall - sumright(all[i][j - 1], all[i][j]) + dp[all[i][j]][0]);
        dp[all[i][j]][1] = min(dp[all[i][j]][1], sumall - sumright(all[i][j - 1], all[i][j]) + dp[all[i][j - 1]][0]);
      }
      dp[all[i][0]][1] = min(dp[all[i][0]][1], sumall - sumright(all[i].back(), all[i][0]) + dp[all[i].back()][0]);
      dp[all[i].back()][1] = min(dp[all[i].back()][1], sumall - sumright(all[i].back(), all[i][0]) + dp[all[i][0]][0]);
    }

    vector<int> twolevel;
    for (auto a : all[i])
      twolevel.push_back(a);
    for (auto a : all[i + 1])
      twolevel.push_back(a);
    sort(twolevel.begin(), twolevel.end());
    int n = twolevel.size();
    for (int j = 0; j < n; j++)
      twolevel.push_back(twolevel[j]);

    for (int j = 0; j < 2; j++)
    {
      int cur = -1;
      for (auto a : twolevel)
        if (type[a] == i)
        {
          if (cur == -1)
            cur = a;
          else if (j == 0)
          {
            if (sumright(cur, a) + dp[cur][1] > dp[a][1])
              cur = a;
          }
          else if (j == 1)
          {
            if (sumright(a, cur) + dp[cur][1] > dp[a][1])
              cur = a;
          }
        }
        else if (cur != -1)
        {
          if (j == 0)
            dp[a][0] = min(dp[a][0], dp[cur][1] + sumright(cur, a));
          else if (j == 1)
            dp[a][0] = min(dp[a][0], dp[cur][1] + sumright(a, cur));
        }
      reverse(twolevel.begin(), twolevel.end());
    }
  }
  if (all[maxtype].size() == 1)
    dp[all[maxtype][0]][1] = dp[all[maxtype][0]][0];
  else
  {
    for (int j = 1; j < all[maxtype].size(); j++)
    {
      dp[all[maxtype][j - 1]][1] = min(dp[all[maxtype][j - 1]][1], sumall - sumright(all[maxtype][j - 1], all[maxtype][j]) + dp[all[maxtype][j]][0]);
      dp[all[maxtype][j]][1] = min(dp[all[maxtype][j]][1], sumall - sumright(all[maxtype][j - 1], all[maxtype][j]) + dp[all[maxtype][j - 1]][0]);
    }
    dp[all[maxtype][0]][1] = min(dp[all[maxtype][0]][1], sumall - sumright(all[maxtype].back(), all[maxtype][0]) + dp[all[maxtype].back()][0]);
    dp[all[maxtype].back()][1] = min(dp[all[maxtype].back()][1], sumall - sumright(all[maxtype].back(), all[maxtype][0]) + dp[all[maxtype][0]][0]);
  }
  int mini = INT_MAX;
  for (auto a : all[maxtype])
    mini = min(mini, dp[a][1]);
  cout << mini << '\n';
}