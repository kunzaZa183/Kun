#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int arr[maxn], heavy[maxn], parent[maxn], head[maxn], siz[maxn];
vector<int> adjlist[maxn];
int dfs(int cur, int par)
{
  siz[cur] = 1;
  parent[cur] = par;
  for (auto a : adjlist[cur])
    if (a != par)
      siz[cur] += dfs(a, cur);
  return siz[cur];
}
void dfs2(int cur, int hd)
{
  head[cur] = hd;
  int maxid = -1, maxnum = 0;
  for (auto a : adjlist[cur])
    if (a != parent[cur])
      if (siz[a] > maxnum)
      {
        maxid = a;
        maxnum = siz[a];
      }
  heavy[cur] = maxid;
  for (auto a : adjlist[cur])
    if (a != parent[cur])
    {
      if (a == heavy[cur])
        dfs2(a, hd);
      else
        dfs2(a, a);
    }
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, qs;
  cin >> n >> qs;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjlist[a - 1].push_back(b - 1), adjlist[b - 1].push_back(a - 1);
  }
  dfs(0, 0);
  while (qs--)
  {
  }
}