#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100000;
struct edge
{
  int a, b, weight;
  edge(int x, int y, int z)
  {
    a = x, b = y, weight = z;
  }
  bool operator<(edge x) const
  {
    return weight > x.weight;
  }
};
int dsu[maxn];
priority_queue<edge> pqe;
int find(int x)
{
  if (dsu[x] == x)
    return dsu[x];
  dsu[x] = find(dsu[x]);
  return dsu[x];
}
int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    dsu[i] = i;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    pqe.emplace(a, b, c);
  }
  int sum = 0;
  int edges = 0;
  while (!pqe.empty())
  {
    edge tmp = pqe.top();
    pqe.pop();
    if (find(tmp.a) != find(tmp.b))
    {
      sum += tmp.weight;
      dsu[find(tmp.a)] = dsu[find(tmp.b)];
      edges++;
    }
  }
  if (edges == n - 1)
    cout << sum << "\n";
  else
    cout << "IMPOSSIBLE\n";
}