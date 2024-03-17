#include <bits/stdc++.h>
#include "resource.h"
using namespace std;
#define int long long

const int maxn = 100000;
vector<int> adjlist[maxn];
vector<int32_t> each;
int where[maxn];
int n;
pair<int, int> all[maxn], vpii[maxn];

struct node
{
  int sum, ct;
  node *l, *r;
  node()
  {
    sum = 0, ct = 0;
    l = NULL, r = NULL;
  }
};
vector<node *> seg;

void build(node *cur, int curl, int curr)
{
  if (curl == curr)
    return;
  node *tmpl = new node, *tmpr = new node;
  cur->l = tmpl, cur->r = tmpr;
  build(tmpl, curl, (curl + curr) / 2), build(tmpr, (curl + curr) / 2 + 1, curr);
}

node *update(node *cur, int curl, int curr, int in, int val)
{
  // cout << curl << ' ' << curr << " " << in << ' ' << val << "\n";
  node *tmp = new node;
  if (curl == curr)
  {
    tmp->sum = val, tmp->ct = 1;
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
  return tmp;
}

pair<int, int> disc[maxn];
int parent[maxn];
int tim = 0;
void eulertour(int cur, int par)
{
  seg.push_back(update(seg.back(), 0, n - 1, where[cur], each[cur]));
  disc[cur].first = tim++;
  parent[cur] = par;
  for (auto a : adjlist[cur])
    if (a != par)
      eulertour(a, cur);
  disc[cur].second = tim - 1;
}

void init_resource(int32_t N, int32_t Q, std::vector<int32_t> A, std::vector<int32_t> U, std::vector<int32_t> V, int32_t G)
{
  // cout << "WHAT";
  each = A;
  n = N;

  for (int i = 0; i < U.size(); i++)
  {
    adjlist[U[i]].push_back(V[i]), adjlist[V[i]].push_back(U[i]);
    vpii[i] = {U[i], V[i]};
  }
  for (int i = 0; i < n; i++)
    all[i] = {each[i], i};
  sort(all, all + n, greater<pair<int, int>>());
  for (int i = 0; i < n; i++)
    where[all[i].second] = i;
  seg.push_back(new node);
  build(seg[0], 0, n - 1);
  eulertour(0, 0);
  // cout << "Y\n";
}

int walk(node *curl, node *curr, int k)
{
  if (curr->ct - curl->ct <= k)
    return curr->sum - curl->sum;
  if (k == 0)
    return 0;
  if (curr->l->ct - curl->l->ct < k)
    return curr->l->sum - curl->l->sum + walk(curl->r, curr->r, k - (curr->l->ct - curl->l->ct));
  return walk(curl->l, curr->l, k);
}

int walk2(node *cur, node *curl, node *curr, int k)
{

  if (curr->ct - curl->ct + cur->ct <= k)
    return curr->sum - curl->sum + cur->sum;
  if (k == 0)
    return 0;
  if (curr->l->ct - curl->l->ct + cur->l->ct < k)
    return (curr->l->sum - curl->l->sum + cur->l->sum) + walk2(cur->r, curl->r, curr->r, k - (curr->l->ct - curl->l->ct + cur->l->ct));
  return walk2(cur->l, curl->l, curr->l, k);
}

long long need_help(int32_t X, int32_t C, int32_t K)
{
  // cout << "X\n";
  int u = vpii[X].first, v = vpii[X].second;
  if (parent[u] != v)
    swap(u, v);
  // cout << disc[u].first << ' ' << disc[u].second << " " << disc[C].first << " " << disc[C].second << '\n';
  if (disc[u].first <= disc[C].first && disc[C].first <= disc[u].second)
    return walk(seg[disc[u].first], seg[disc[u].second + 1], K);
  return walk2(seg[disc[u].first], seg[disc[u].second + 1], seg[n], K);
}

int32_t main()
{
  freopen("in.txt", "r", stdin);
  freopen("sol.txt", "w", stdout);
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
    int32_t X, C, K;
    assert(scanf("%d %d %d", &X, &C, &K) == 3);
    printf("%lld\n", need_help(X, C, K));
  }
}