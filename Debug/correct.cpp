#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300300;
const int K = 20;
int a[N], d1[N], d2[N];
int ans[N];
int dp1[K + 1][N], dp2[K + 1][N];
int query1(int l, int r)
{
  r--;
  int k = 31 - __builtin_clz(r - l + 1);
  return min(dp1[k][l], dp1[k][r - (1 << k) + 1]);
}
int query2(int l, int r)
{
  r--;
  int k = 31 - __builtin_clz(r - l + 1);
  return max(dp2[k][l], dp2[k][r - (1 << k) + 1]);
}
int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("input.txt", "r", stdin);
  freopen("correctoutput.txt", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  n--;
  for (int i = 1; i <= n; i++)
  {
    d1[i] = max(a[i + 1], a[i]);
    d2[i] = min(a[i + 1], a[i]);
  }
  // build RMQ
  for (int i = 1; i <= n; i++)
  {
    dp1[0][i] = d1[i];
    dp2[0][i] = d2[i];
  }
  for (int i = 0; i < 19; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dp1[i + 1][j] = dp1[i][j];
      dp2[i + 1][j] = dp2[i][j];
    }
    for (int j = 1; j + (2 << i) - 1 <= n; j++)
    {
      dp1[i + 1][j] = min(dp1[i][j], dp1[i][j + (1 << i)]);
      dp2[i + 1][j] = max(dp2[i][j], dp2[i][j + (1 << i)]);
    }
  }
  n++;
  // ans[1]
  int ans1 = 1e9;
  for (int i = 2; i < n; i += 2)
  {
    if (a[i] < a[1] && a[i + 1] < a[1])
      ans1 = min(ans1, i + 1);
    if (a[i] > a[1] && a[i + 1] > a[1])
      ans1 = min(ans1, i + 1);
  }
  if (ans1 == 1e9)
    cout << -1 << ' ';
  else
    cout << ans1 << ' ';
  for (int i = 2; i < n; i++)
  {
    if (a[i - 1] < a[i] && a[i + 1] < a[i])
    {
      cout << 3 << ' ';
      continue;
    }
    if (a[i - 1] > a[i] && a[i + 1] > a[i])
    {
      cout << 3 << ' ';
      continue;
    }
    int ans = 1e9;
    if (i + 2 <= n && (query1(i + 1, n) < a[i] || query2(i + 1, n) > a[i]))
    {
      int l = i + 2, r = n;
      while (l < r)
      {
        int mid = (l + r) / 2;
        if (query1(i + 1, mid) < a[i] || query2(i + 1, mid) > a[i])
          r = mid;
        else
          l = mid + 1;
      }
      int sz = l - i + 1;
      ans = min(ans, sz + (sz % 2 == 0));
    }
    if (i >= 3 && (query1(1, i - 1) < a[i] || query2(1, i - 1) > a[i]))
    {
      int l = 1, r = i - 2;
      while (l < r)
      {
        int mid = (l + r + 1) / 2;
        if (query1(mid, i - 1) < a[i] || query2(mid, i - 1) > a[i])
          l = mid;
        else
          r = mid - 1;
      }
      int sz = i - l + 1;
      ans = min(ans, sz + (sz % 2 == 0));
    }
    if (ans == 1e9)
      cout << -1 << ' ';
    else
      cout << ans << ' ';
  }
  ans1 = 1e9;
  for (int i = n - 1; i > 1; i -= 2)
  {
    if (a[i] < a[n] && a[i - 1] < a[n])
      ans1 = min(ans1, n - i + 2);
    if (a[i] > a[n] && a[i - 1] > a[n])
      ans1 = min(ans1, n - i + 2);
  }
  if (ans1 == 1e9)
    cout << -1 << ' ';
  else
    cout << ans1 << ' ';
  cout << "\n";
}