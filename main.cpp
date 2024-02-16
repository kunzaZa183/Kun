#include <bits/stdc++.h>
using namespace std;
const int maxn = 1501, logn = 11;
int arr[maxn][maxn], right[maxn][4 * maxn], down[maxn][4 * maxn], rect[maxn][maxn];
void buildright(int curx, int curin, int curl, int curr)
{
  buildright(curx, curin * 2 + 1, curl, (curl + curr) / 2), buildright(curx, curin * 2 + 2, (curl + curr) / 2 + 1, curr);
  
}
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
  for (int i = 0; i <= logn; i++)
}