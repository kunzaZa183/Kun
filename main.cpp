#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int arr[maxn][maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++)
      if (s[j - 1] == '*')
        arr[i][j] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
  while (q--)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << arr[c][d] - arr[c][b - 1] - arr[a - 1][d] + arr[a - 1][b - 1] << '\n';
  }
}