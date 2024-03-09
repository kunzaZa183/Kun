#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vvi;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("correctoutput.txt", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vvi.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    cin >> vvi[0][i];
  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j++)
      vvi[i][j] = min(vvi[i - 1][j], vvi[i - 1][j - 1]) + vvi[0][j];
  int qs;
  cin >> qs;
  while (qs--)
  {
    int a, b;
    cin >> a >> b;
    cout << vvi[a - 1][b - 1] << "\n";
  }
}
