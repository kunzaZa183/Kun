#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjlist;
string s;
vector<pair<int, int>> vi;
void dfs(int cur, int par, int curd)
{
  vi.emplace_back(curd, cur);
  for (auto a : adjlist[cur])
    if (a != par)
      dfs(a, cur, curd + 1);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n;
    adjlist.clear();
    adjlist.resize(n);
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adjlist[a].push_back(b), adjlist[b].push_back(a);
    }
    vi.clear();
    dfs(0, 0, 0);
    pair<int, int> maxi = vi.front();
    for (auto& a : vi)
      maxi = max(maxi, a);
    vi.clear();
    dfs(maxi.second, -1, 0);
    pair<int, int> maxi2 = vi.front();
    for (auto a : vi)
      maxi2 = max(maxi2, a);
    if (s[maxi.second] != s[maxi2.second])
      cout << maxi2.first << '\n';
    else
    {
      int maxdist = -1;
      for (auto a : vi)
        if (s[a.second] != s[maxi.second])
          maxdist = max(maxdist, a.first);
      vi.clear();
      dfs(maxi2.second, -1, 0);
      for (auto a : vi)
        if (s[a.second] != s[maxi.second])
          maxdist = max(maxdist, a.first);
      cout << maxdist << '\n';
    }
  }
}