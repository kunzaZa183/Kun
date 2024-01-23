#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
vector<int> adjlist[maxn];
bitset<maxn> bsmn;
void dfs(int cur)
{
  bsmn[cur] = 1;
  for (auto a : adjlist[cur])
    dfs(a);
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adjlist[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
  {
    bsmn.reset();
    dfs(i);
    for (int j = 0; j < n; j++)
      if (!bsmn[j])
        goto A;
    cout << i + 1 << '\n';
    return 0;
  A:;
  }
  cout << "-1\n";
}