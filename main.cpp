#include <bits/stdc++.h>
using namespace std;
const int maxn = 1502, logn = 11;
int arr[maxn][maxn], rect[maxn][maxn];
int pref[maxn][maxn], suf[maxn][maxn];
int topl[maxn][maxn], topr[maxn][maxn], botr[maxn][maxn], botl[maxn][maxn];
int col2[maxn][maxn], row2[maxn][maxn];
int row[maxn], col[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> arr[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
  for (int i = k; i <= n; i++)
    for (int j = k; j <= m; j++)
      rect[i][j] = arr[i][j] - arr[i - k][j] - arr[i][j - k] + arr[i - k][j - k];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      pref[i][j] = max(rect[i][j], pref[i][j - 1]);
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      suf[i][j] = max(rect[i][j], suf[i][j - 1]);

  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      topl[i][j] = max(topl[i - 1][j], pref[i][j]);
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      topr[i][j] = max(topr[i - 1][j], suf[i][j]);
  for (int j = 1; j <= m; j++)
    for (int i = n; i >= 1; i--)
      botl[i][j] = max(botl[i + 1][j], pref[i][j]);
  for (int j = 1; j <= m; j++)
    for (int i = n; i >= 1; i--)
      botr[i][j] = max(botr[i + 1][j], suf[i][j]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      row[i] = max(row[i], rect[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      col[j] = max(col[j], rect[i][j]);

  for (int i = 1; i <= n; i++)
  {
    row2[i][i] = row[i];
    for (int j = i + 1; j <= n; j++)
      row2[i][j] = max(row2[i][j - 1], row[j]);
  }
  for (int i = 1; i <= m; i++)
  {
    col2[i][i] = col[i];
    for (int j = i + 1; j <= m; j++)
      col2[i][j] = max(col2[i][j - 1], col[j]);
  }

  int maxi = 0;

  for (int i = k + 1; i <= n; i++)
    for (int j = i + k; j <= n - k; j++)
      maxi = max(maxi, row2[1][i - 1] + row2[i][j - 1] + row2[j][n]);

  for (int i = k + 1; i <= m; i++)
    for (int j = i + k; j <= m - k; j++)
      maxi = max(maxi, col2[1][i - 1] + col2[i][j - 1] + col2[j][m]);

  if (m >= 2 * k && n >= 2 * k)
  {
    for (int i = k; i <= n - k; i++)
      for (int j = k; j <= m - k; j++)
      {
        int a = topl[i][j], b = topr[i][j + 1], c = botl[i + 1][j], d = botr[i + 1][j + 1];
        maxi = max({maxi, a + b + c, a + b + d, a + c + d, b + c + d});
      }
  }

  cout<<maxi<<"\n";
}