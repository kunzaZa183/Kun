#include <bits/stdc++.h>
using namespace std;
#define int long long
const int BIGNUM = 1'000'000'000'000'000;
struct kun
{
  pair<int, int> higher, lower; // depth subtree
  kun()
  {
    higher = {BIGNUM,BIGNUM}, lower = {BIGNUM, BIGNUM};
  }
};
vector<vector<pair<int, int>>> adjlist;
vector<bool> node;
vector<int> siz;
int dfs(int cur, int par)
{
  siz[cur] = 1;
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfs(a.first, cur);
  return siz[cur];
}
int findcen(int cur, int par, int n)
{
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      if (siz[a.first] * 2 > n)
        return findcen(a.first, cur, n);
  return cur;
}
int dfscen(int cur, int par, long long dist, int depth, int head, map<long long, kun> &mii)
{
  siz[cur] = 1;
  if (depth < mii[dist].higher.first)
  {
    swap(mii[dist].higher, mii[dist].lower);
    mii[dist].higher = {depth, head};
  }
  else if (depth < mii[dist].lower.first)
    mii[dist].lower = {depth, head};
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfscen(a.first, cur, dist + a.second, depth + 1, head, mii);
  return siz[cur];
}
int anssubtree(int root, int n, int k)
{
  dfs(root, root);
  int centroid = findcen(root, root, n);
  map<long long, kun> mii; /*length vector<depth, subtree>*/
  for (auto a : adjlist[centroid])
    if (node[a.first])
      dfscen(a.first, centroid, a.second, 1, a.first, mii);
  mii[0].lower = {0, 0}, mii[0].higher = {0, 0};
  int shortest = BIGNUM;
  for (auto &a : mii)
    if (a.first <= k / 2)
    {
      kun tmp = mii[k - a.first];
      if (a.second.higher.second != tmp.higher.second)
        shortest = min(shortest, a.second.higher.first + tmp.higher.first);
      if (a.second.lower.second != tmp.higher.second)
        shortest = min(shortest, a.second.lower.first + tmp.higher.first);
      if (a.second.higher.second != tmp.lower.second)
        shortest = min(shortest, a.second.higher.first + tmp.lower.first);
      if (a.second.lower.second != tmp.lower.second)
        shortest = min(shortest, a.second.lower.first + tmp.lower.first);
    }
  node[centroid] = 0;
  for (auto a : adjlist[centroid])
    if (node[a.first])
      shortest = min(shortest, anssubtree(a.first, siz[a.first], k));
  return shortest;
}
int32_t best_path(int32_t N, int32_t K, int32_t H[][2], int32_t L[])
{
  adjlist.resize(N);
  for (int i = 0; i < N - 1; i++)
    adjlist[H[i][0]].push_back({H[i][1], L[i]}), adjlist[H[i][1]].push_back({H[i][0], L[i]});
  node.resize(N, 1);
  siz.resize(N);
  int x = anssubtree(0, N, K);
  if (x == BIGNUM)
    x = -1;
  return x;
}