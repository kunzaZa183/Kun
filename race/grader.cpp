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
int dfscen(int cur, int par, int dist, int depth, map<int, int> &mii, vector<vector<pair<int, int>>> &adjlist, vector<bool> &node, vector<int> &siz)
{
  siz[cur] = 1;
  if (mii.count(dist))
    mii[dist] = min(mii[dist], depth);
  else
    mii[dist] = depth;
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfscen(a.first, par, dist + a.second, depth + 1, mii, adjlist, node, siz);
  return siz[cur];
}
int anssubtree(vector<vector<pair<int, int>>> &adjlist, vector<bool> &node, int n, int k)
{
  int root = node.front();
  vector<int> siz(adjlist.size());
  dfs(root, root, adjlist, node, siz);
  int centroid = findcen(root, root, adjlist, node, siz, n);
  map<int, int> mii;
  dfscen(centroid, centroid, 0, 0, mii, adjlist, node, siz);
  int shortest = INT_MAX;
  for (auto a : mii)
    if (mii.count(k - a.second))
      shortest = min(shortest, shortest + mii[k - a.second]);
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

#define MAX_N 500000

static int N, K;
static int H[MAX_N][2];
static int L[MAX_N];
static int solution;

inline void my_assert(int e)
{
  if (!e)
    abort();
}

void read_input()
{
  int i;
  my_assert(2 == scanf("%d %d", &N, &K));
  for (i = 0; i < N - 1; i++)
    my_assert(3 == scanf("%d %d %d", &H[i][0], &H[i][1], &L[i]));
  my_assert(1 == scanf("%d", &solution));
}

int main()
{
  int ans;
  read_input();
  ans = best_path(N, K, H, L);
  if (ans == solution)
    printf("Correct.\n");
  else
    printf("Incorrect. Returned %d, Expected %d.\n", ans, solution);

  return 0;
}
