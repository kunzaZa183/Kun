#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> dp;
vector<int> vi;
int recurdp(int in, int l)
{
  if (l == -1)
    return 0;
  if (dp[in][l] == -1)
  {
    if (in == 0)
      dp[in][l] = 0;
    else
      dp[in][l] = 1;
    for (int i = in + 1; i < dp.size(); i++)
      if (vi[in] < vi[i])
        dp[in][l] += recurdp(i, l);
      else if (vi[in] > vi[i])
        dp[in][l] += recurdp(i, l - 1);
  }
  return dp[in][l];
}
vector<int> cur;
void findans(int in, int l, int k)
{
  if (l == -1)
    return;
  vector<pair<int, int>> order; // value in
  for (int i = in + 1; i < dp.size(); i++)
    order.push_back({ vi[i], i });
  sort(order.begin(), order.end());
  if (k == 0 && in != 0)
  {
    for (auto a : cur)
      cout << a << ' ';
    cout << '\n';
    exit(0);
  }
  k--;
  for (auto a : order)
    if (vi[in] < a.first)
    {
      if (k < recurdp(a.second, l))
      {
        cur.push_back(a.first);
        findans(a.second, l, k);
      }
      else
        k -= recurdp(a.second, l);
    }
    else if (vi[in] > a.first)
    {
      if (k < recurdp(a.second, l - 1))
      {
        cur.push_back(a.first);
        findans(a.second, l - 1, k);
      }
      else
        k -= recurdp(a.second, l - 1);
    }
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  vi.resize(n + 1, -1);
  for (int i = 1; i <= n; i++)
    cin >> vi[i];
  if (k == 0)
  {
    cout << "0\n";
    return 0;
  }
  dp.resize(n + 1, vector<int>(l + 1, -1));
  vector<pair<int, int>> order;
  for (int i = 1; i <= n; i++)
    order.push_back({ vi[i], i });
  sort(order.begin(), order.end());
  for (int i = 0; i < order.size(); i++)
    if (recurdp(order[i].second, l) <= k)
      k -= recurdp(order[i].second, l);
    else
    {
      cur.push_back(order[i].first);
      findans(order[i].second, l, k);
    }
  cout << "-1\n";
}