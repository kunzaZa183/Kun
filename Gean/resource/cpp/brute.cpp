#include <bits/stdc++.h>
#include "resource.h"
using namespace std;
#define int long long

const int maxn = 3000;
vector<int> adjlist[maxn];
vector<int32_t> each;
vector<pair<int, int>> vpii;

void init_resource(int32_t N, int32_t Q, std::vector<int32_t> A, std::vector<int32_t> U, std::vector<int32_t> V, int32_t G)
{
  each = A;
  for (int i = 0; i < U.size(); i++)
  {
    adjlist[U[i]].push_back(V[i]), adjlist[V[i]].push_back(U[i]);
    vpii.emplace_back(U[i], V[i]);
    if (U[i] > V[i])
      swap(U[i], V[i]);
  }
}

vector<int> all;
void dfs(int cur, int par, pair<int, int> cant)
{
  // cout << "CUR = " << cur << "\n";
  int tmpi = cur, tmpj = par;
  if (tmpi > tmpj)
    swap(tmpi, tmpj);
  if (make_pair(tmpi, tmpj) == cant)
    return;
  all.push_back(each[cur]);
  for (auto a : adjlist[cur])
    if (a != par)
      dfs(a, cur, cant);
}

long long need_help(int32_t X, int32_t C, int32_t K)
{
  all.clear();
  dfs(C, C, vpii[X]);
  int total = 0;
  sort(all.begin(), all.end(),greater<int>());
  for (int i = 0; i < min(K, int32_t(all.size())); i++)
    total += all[i];
  return total;
}