#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjlist;
vector<int> heavy, headvi, depthvi, pos, parentvi;
int dfs(int cur, int par, int depth)
{
  depthvi[cur] = depth;
  parentvi[cur] = par;
  int siz = 1, maxsiz = INT_MIN;
  for (auto a : adjlist[cur])
    if (a != par)
    {
      int x = dfs(a, cur, depth + 1);
      siz += x;
      if (maxsiz < x)
      {
        maxsiz = x;
        heavy[cur] = a;
      }
    }
  return siz;
}
int cur_pos = 0;
void decomp(int cur, int head)
{
  headvi[cur] = head, pos[cur] = cur_pos++;
  if (heavy[cur] != -1)
    decomp(heavy[cur], head);
  for (auto a : adjlist[cur])
    if (a != parentvi[cur] && a != heavy[cur])
      decomp(a, a);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n, m;
    cin >> n >> m;
    adjlist.clear();
    adjlist.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adjlist[a].push_back(b), adjlist[b].push_back(a);
    }
    headvi.clear(), pos.clear(), heavy.clear(), depthvi.clear(), parentvi.clear();
    headvi.resize(n), pos.resize(n), heavy.resize(n, -1), depthvi.resize(n), parentvi.resize(n);
    
  }
}