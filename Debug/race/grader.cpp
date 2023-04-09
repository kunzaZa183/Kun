// https://contest.yandex.com/ioi/contest/571/problems/B/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adjlist;
vector<bool> node;
struct kun
{
  pair<int, int> higher, lower; // depth subtree
  kun()
  {
    higher = { 1000000000, 1000000000 }, lower = { 1000000000, 1000000000 };
  }
};
int dfs(int cur, int par, vector<int>& siz)
{
  siz[cur] = 1;
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfs(a.first, cur, siz);
  return siz[cur];
}
int findcen(int cur, int par, vector<int>& siz, int n)
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
    return cur;
  return findcen(maxid, cur, siz, n);
}
int dfscen(int cur, int par, long long dist, int depth, int head, map<long long, kun>& mii, vector<int>& siz)
{
  siz[cur] = 1;
  if (depth < mii[dist].higher.first)
  {
    swap(mii[dist].higher, mii[dist].lower);
    mii[dist].higher = { depth, head };
  }
  else if (depth < mii[dist].lower.first)
    mii[dist].lower = { depth, head };
  for (auto a : adjlist[cur])
    if (a.first != par && node[a.first])
      siz[cur] += dfscen(a.first, cur, dist + a.second, depth + 1, head, mii, siz);
  return siz[cur];
}
int anssubtree(int root, int n, int k)
{
  vector<int> siz(adjlist.size());
  dfs(root, root, siz);
  int centroid = findcen(root, root, siz, n);
  map<long long, kun> mii; /*length vector<depth, subtree>*/
  for (auto a : adjlist[centroid])
    if (node[a.first])
      dfscen(a.first, centroid, a.second, 1, a.first, mii, siz);
  mii[0].lower = { 0, 0 }, mii[0].higher = { 0, 0 };
  int shortest = 1000000000;
  for (auto& a : mii)
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
    adjlist[H[i][0]].push_back({ H[i][1], L[i] }), adjlist[H[i][1]].push_back({ H[i][0], L[i] });
  node.resize(N, 1);
  int x = anssubtree(0, N, K);
  if (x == 1000000000)
    x = -1;
  return x;
}

#define MAX_N 500000

static int32_t N, K;
static int32_t H[MAX_N][2];
static int32_t L[MAX_N];
static int32_t solution;

inline void my_assert(int32_t e)
{
  if (!e)
    abort();
}

void read_input()
{
  int32_t i;
  my_assert(2 == scanf("%d %d", &N, &K));
  for (i = 0; i < N - 1; i++)
    my_assert(3 == scanf("%d %d %d", &H[i][0], &H[i][1], &L[i]));
  my_assert(1 == scanf("%d", &solution));
}

int32_t main()
{
  int32_t ans;
  // freopen("grader.in.4", "r", stdin);
  // freopen("out.txt", "w", stdout);
  read_input();
  ans = best_path(N, K, H, L);
  if (ans == solution)
    printf("Correct.\n");
  else
    printf("Incorrect. Returned %d, Expected %d.\n", ans, solution);

  return 0;
}
