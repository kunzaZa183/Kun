#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000, logn = 20;
int lca[logn][maxn];
int arr[maxn];
vector<int> adjlist[maxn];
int depth[maxn];
void dfs(int cur, int par, int curd)
{
  depth[cur] = curd;
  lca[0][cur] = par;
  for (auto a : adjlist[cur])
    if (a != par)
      dfs(a, cur, curd + 1);
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++)
  {
    int x;
    cin >> x;
    x--;
    adjlist[x].push_back(i);
  }
  dfs(0, 0, 0);
  for (int i = 1; i < logn; i++)
    for (int j = 0; j < n; j++)
      lca[i][j] = lca[i - 1][lca[i - 1][j]];
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (depth[a] > depth[b])
      swap(a, b);
    for (int i = logn - 1; i >= 0; i--)
      if ((depth[b] - depth[a]) & (1 << i))
        b = lca[i][b];
    for (int i = logn - 1; i >= 0; i--)
      if (lca[i][a] != lca[i][b])
        a = lca[i][a], b = lca[i][b];
    if (a != b)
      a = lca[0][a], b = lca[0][b];
    cout << a + 1 << "\n";
  }
}