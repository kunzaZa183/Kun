#include <bits/stdc++.h>
#include "resource.h"
using namespace std;
#define int long long

const int maxn = 100000;
vector<int> adjlist[maxn];
vector<int32_t> each;
vector<pair<int, int>> vpii;
int where[maxn];
pair<int,int> all[maxn];

struct node
{
  int sum, ct;
  node *l, *r;
  node()
  {
    sum = 0, ct = 0;
    l = NULL, r = NULL;
  }
}all[maxn];

node *update(node *cur, int curl, int curr, int in, int val)
{
  node *tmp = new node;
  if (curl == curr)
  {
    tmp->sum = val;
    return tmp;
  }
  int mid = (curl + curr) / 2;
  if (in <= mid)
  {
    tmp->l = update(cur->l, curl, mid, in, val);
    tmp->r = cur->r;
  }
  else if (in > mid)
  {
    tmp->l = cur->l;
    tmp->r = update(cur->r, mid + 1, curr, in, val);
  }
  tmp->sum = tmp->l->sum + tmp->r->sum, tmp->ct = tmp->l->ct + tmp->r->ct;
}

pair<int, int> disc[maxn];
int parent[maxn];
int tim = 0;
void eulertour(int cur, int par)
{
  disc[cur].first = tim++;
  parent[cur] = par;
  for (auto a : adjlist[cur])
    if (a != par)
      eulertour(a, cur);
  disc[cur].second = tim - 1;
}

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
  eulertour(0,0);
  for(int i=0;i<N;i++)
}

long long need_help(int32_t X, int32_t C, int32_t K)
{
}
int32_t main()
{
  int32_t N, Q, G;
  assert(scanf("%d %d %d", &N, &Q, &G) == 3);
  std::vector<int32_t> A(N), U(N - 1), V(N - 1);
  for (int i = 0; i < N; i++)
  {
    assert(scanf("%d", &A[i]) == 1);
  }
  for (int i = 0; i < N - 1; i++)
  {
    assert(scanf("%d %d", &U[i], &V[i]) == 2);
  }
  init_resource(N, Q, A, U, V, G);
  for (int i = 0; i < Q; i++)
  {
    int X, C, K;
    assert(scanf("%d %d %d", &X, &C, &K) == 3);
    printf("%lld\n", need_help(X, C, K));
  }
}