#include <bits/stdc++.h>
#include "castle.h"
using namespace std;
const int maxn = 100000;
bitset<maxn> visited;
vector<int> adjlist[maxn];
vector<int> a, b;
void dfs(int cur)
{
  visited[cur] = 1;
  for (auto a : adjlist[cur])
    if (!visited[a])
      dfs(a);
}
int main()
{
  freopen("correct.txt", "w", stdout);
  int n, m, q, y;
  castle_init(n, m, q, y);
  castle_read_map(a, b);
  for (int i = 0; i < m; i++)
    adjlist[a[i]].push_back(b[i]), adjlist[b[i]].push_back(a[i]);
  while (q--)
  {
    int type, x, y;
    castle_read_event(type, x, y);
    if (type == 1)
    {
      y = b[x];
      x = a[x];
      adjlist[x].erase(find(adjlist[x].begin(), adjlist[x].end(), y));
      adjlist[y].erase(find(adjlist[y].begin(), adjlist[y].end(), x));
    }
    else if (type == 2)
    {
      visited.reset();
      dfs(x);
      if (visited[y])
        castle_answer(1);
      else
        castle_answer(0);
    }
  }
}