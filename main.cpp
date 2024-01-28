#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int arr[maxn][maxn], qsum[maxn][maxn], toright[maxn][maxn], todown[maxn][maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++)
      arr[i][j] = s[j - 1] - '0';
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j < m; j++)
      toright[i][j] = arr[i][j] && arr[i][j + 1];

  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++)
      todown[i][j] = arr[i][j] && arr[i + 1][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      qsum[i][j] = arr[i][j] + qsum[i - 1][j] + qsum[i][j - 1] - qsum[i - 1][j - 1];
      toright[i][j] += toright[i - 1][j] + toright[i][j - 1] - toright[i - 1][j - 1];
      todown[i][j] += todown[i - 1][j] + todown[i][j - 1] - todown[i - 1][j - 1];
    }

  while (q--)
  {
    pair<int, int> topl, botr;
    cin >> topl.first >> topl.second >> botr.first >> botr.second;
    int blues = qsum[botr.first][botr.second] - qsum[topl.first - 1][botr.second] - qsum[botr.first][topl.second - 1] + qsum[topl.first - 1][topl.second - 1];
    int connect = 0;
    connect += toright[botr.first][botr.second - 1] - toright[botr.first][topl.second - 1] - toright[topl.first - 1][botr.second - 1] + toright[topl.first - 1][topl.second - 1];
    connect += todown[botr.first - 1][botr.second] - todown[botr.first - 1][topl.second - 1] - todown[topl.first - 1][botr.second] + todown[topl.first - 1][topl.second - 1];
    cout << blues - connect << '\n';
  }
}