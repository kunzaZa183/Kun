#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int maxn = 100000;
struct type
{
  int cent, dist, branch;
  type(int a, int b, int c)
  {
    cent = a, dist = b, branch = c;
  }
};
vector<int> adjlist[maxn];
vector<type> allcents[maxn]; // cent dist
bitset<maxn> used;
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> spii[maxn]; // farther
vector<tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>> mit[maxn];
int treesiz[maxn];
int dfs(int cur, int par)
{
  // cout << cur << ' ' << par << "\n";
  treesiz[cur] = 1;
  for (auto a : adjlist[cur])
    if (!used[a] && a != par)
      treesiz[cur] += dfs(a, cur);
  return treesiz[cur];
}
int findcent(int cur, int par, int maxsiz)
{
  for (auto a : adjlist[cur])
    if (!used[a] && a != par)
      if (treesiz[a] > maxsiz / 2)
        return findcent(a, cur, maxsiz);
  return cur;
}
void dfs2(int cur, int par, int curdist, int cent, int branch)
{
  allcents[cur].emplace_back(cent, curdist, branch);
  for (auto a : adjlist[cur])
    if (a != par && !used[a])
      dfs2(a, cur, curdist + 1, cent, branch);
}
void decompo(int cur)
{
  // cout << "HI: " << cur << "\n";
  dfs(cur, cur);
  // cout << "X\n";
  int cent = findcent(cur, cur, treesiz[cur]);
  // cout << "X\n";
  int ct = 0;
  for (auto a : adjlist[cent])
    if (!used[a])
      dfs2(a, cent, 1, cent, ct++);
  mit[cent].resize(ct);
  // cout << "X\n";
  used[cent] = 1;
  for (auto a : adjlist[cent])
    if (!used[a])
      decompo(a);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adjlist[a].push_back(b), adjlist[b].push_back(a);
  }
  decompo(0);
  for (int i = 0; i < n; i++)
    allcents[i].emplace_back(i, 0, -1);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << i << " ";
  //   for (auto a : allcents[i])
  //     cout << a.cent << "," << a.dist << ',' << a.branch << ' ';
  //   cout << "\n";
  // }
  int dis = 0;
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int v, k;
      cin >> v >> k;
      v--;
      for (auto a : allcents[v])
        if (a.dist <= k)
        {
          // cout << "INSERT: " << a.cent << " " << k - a.dist << ' ' << a.branch << "\n";
          spii[a.cent].insert({k - a.dist, dis++});
          if (a.branch != -1)
            mit[a.cent][a.branch].insert({k - a.dist, dis++});
        }
    }
    else if (type == 2)
    {
      int x;
      cin >> x;
      x--;
      int total = 0;
      for (auto a : allcents[x])
      {
        total += spii[a.cent].size() - spii[a.cent].order_of_key({a.dist, INT_MIN});
        if (a.branch != -1)
          total -= mit[a.cent][a.branch].size() - mit[a.cent][a.branch].order_of_key({a.dist, INT_MIN});
      }
      cout << total << '\n';
    }
  }
}