#include "race.h"
#include <bits/stdc++.h>
using namespace std;
int dfs(int cur, int par, vector<vector<pair<int, int>>> &adjlist, vector<bool> &node, vector<int> &siz)
{
  siz[cur] = 1;
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfs(a.first, cur, adjlist, node, siz);
  return siz[cur];
}
int findcen(int cur, int par, vector<vector<pair<int, int>>> &adjlist, vector<bool> &node, vector<int> &siz, int n)
{
  int maxi = INT_MIN, maxid;
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      if (siz[a.first] > maxi)
      {
        maxi = siz[a.first];
        maxid = a.first;
      }
  if (maxi <= n / 2)
    return maxid;
  return findcen(maxid, cur, adjlist, node, siz, n);
}
int dfscen(int cur, int par, int dist, int depth, int head, map<int, vector<pair<int, int>>> &mii, vector<vector<pair<int, int>>> &adjlist, vector<bool> &node, vector<int> &siz)
{
  siz[cur] = 1;
  if (mii[dist].size() <= 1)
  {
    mii[dist].push_back({depth, head});
    if (mii[dist].back().first < mii[dist].front().first)
      swap(mii[dist].back(), mii[dist].front());
  }
  else if (mii[dist].size() == 2)
  {
    if (depth < mii[dist].front().first)
    {
      swap(mii[dist].front(), mii[dist].back());
      mii[dist].front() = {depth, head};
    }
    else if (depth < mii[dist].back().first)
      mii[dist].back() = {depth, head};
  }
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfscen(a.first, par, dist + a.second, depth + 1, head, mii, adjlist, node, siz);
  return siz[cur];
}
int anssubtree(vector<vector<pair<int, int>>> &adjlist, vector<bool> &node, int n, int k)
{
  int root = node.front();
  vector<int> siz(adjlist.size());
  dfs(root, root, adjlist, node, siz);
  int centroid = findcen(root, root, adjlist, node, siz, n);
  map<int, vector<pair<int, int>>> mii; /*length vector<depth, subtree>*/
  for (auto a : adjlist[centroid])
    dfscen(a.first, centroid, a.second, 1, a.first, mii, adjlist, node, siz);
  int shortest = INT_MAX;
  for (auto a : mii)
    for (auto b : a.second)           // O(1)
      for (auto c : mii[k - a.first]) // O(1)
        if (b.second != c.second)
          shortest = min(shortest, b.first + c.first);
  node[centroid] = 0;
  for (auto a : adjlist[centroid])
    shortest = min(shortest, anssubtree(adjlist, node, siz[a.first], k));
  return shortest;
}
int32_t best_path(int32_t N, int32_t K, int32_t H[][2], int32_t L[])
{
  vector<vector<pair<int, int>>> adjlist;
  for (int i = 0; i < N - 1; i++)
    adjlist[H[i][0]].push_back({H[i][0], L[i]}), adjlist[H[i][1]].push_back({H[i][0], L[i]});
  vector<bool> vb(N, 1);
  return anssubtree(adjlist, vb, N, K);
}
