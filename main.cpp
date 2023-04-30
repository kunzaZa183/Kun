#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
struct edge
{
  int a, b, weight;
  friend bool operator<(edge a, edge b)
  {
    if (a.weight != b.weight)
      return a.weight < b.weight;
    if (a.a != b.a)
      return a.a < b.a;
    if (a.b != b.b)
      return a.b < b.b;
  }
};
vector<vector<pair<int, int>>> adjlist; // in time
vector<bool> important;
vector<int> subtreesize;
vector<bool> in;
set<edge> se;
void findsubtreesize(int node, int par)
{
  subtreesize[node] = 1;
  for (auto a : adjlist[node])
    if (a.first != par && in[a.first])
    {
      findsubtreesize(a.first, node);
      subtreesize[node] += subtreesize[a.first];
    }
}
int findcentroid(int node, int par, int n)
{
  int maxi = INT_MIN, maxid;
  for (auto a : adjlist[node])
    if (a.first != par && in[a.first])
      if (subtreesize[a.first] > 2 * n)
        return findcentroid(a.first, node, n);
  return node;
}
void process(int node, int par, map<pair<int, int>, int> &mpiii)
{
  if (important[node] && !se.empty())
    mpiii[{se.rbegin()->a, se.rbegin()->b}]++;
  for (auto a : adjlist[node])
    if (a.first != in[node] && a.first != par)
    {
      se.insert({min(node, a.first), max(node, a.first), a.second});
      process(a.first, node, mpiii);
      se.erase({min(node, a.first), max(node, a.first), a.second});
    }
}
int centroid(int node)
{
  findsubtreesize(node, node);
  int cent = findcentroid(node, node, subtreesize[node]);
  vector<map<pair<int, int>, int>> vmpiii(adjlist[cent].size());
  int ct = 0;
  for (auto a : adjlist[cent])
    if (in[a.first])
      process(a.first, cent, vmpiii[ct++]);
  tree<edge, null_type, less<edge>, rb_tree_tag, tree_order_statistics_node_update> pbds;
  for (auto &a : vmpiii)
    for (auto b : a)
      pbds.insert({b.first.first, b.first.second, b.second});
  for (auto &a : vmpiii)
  {
    for (auto b : a)
      pbds.erase({b.first.first, b.first.second, b.second});
    // i cant
    for (auto b : a)
      pbds.insert({b.first.first, b.first.second, b.second});
    
  }
  in[cent] = 0;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  important.resize(n);
  while (m--)
  {
    int x;
    cin >> x;
    important[x] = 1;
  }
  adjlist.resize(n);
  for (int i = 0; i < n - 1; i++)
  {
    int p, q, t;
    cin >> p >> q >> t;
    adjlist[p].push_back({q, t}), adjlist[q].push_back({p, t});
  }
  subtreesize.resize(n);
  in.resize(n, 1);
}