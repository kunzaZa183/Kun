#include "updown.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000;
map<pair<int, int>, int> mpiii;
int dsu[maxn], rank[maxn];
int find(int x)
{
  if (dsu[x] == x)
    return dsu[x];
  dsu[x] = find(dsu[x]);
  return dsu[x];
}
vector<int> updown(int N, int M, vector<int> U, vector<int> V)
{
  for (int i = 0; i < M; i++)
    if (U[i] > V[i])
      swap(U[i], V[i]);
  for (int i = 0; i < 2 * N; i++)
  {
    dsu[i] = i;
    ::rank[i] = 1;
  }
  for (int i = 0; i < M; i++)
  {
    int x = find(U[i]), y = find(N + V[i]);
    // cout << x << ' ' << y << "\n";
    if (x != y)
    {
      ::rank[x] += ::rank[y];
      ::rank[y] = 0;
      dsu[y] = dsu[x];
    }
  }
  for (int i = 0; i < N; i++)
    mpiii[{min(find(i), find(N + i)), max(find(i), find(N + i))}]++;
  vector<int> ans(N);
  for (int i = 0; i < N; i++)
  {
    // cout << i << " " << ::rank[find(i)] << " " << ::rank[find(i + N)] << "\n";
    if (find(i) == find(i + N))
      ans[i] = ::rank[find(i)] - mpiii[{find(i), find(i)}] - 1;
    else
      ans[i] = ::rank[find(i)] + ::rank[find(i + N)] - 1 - mpiii[{min(find(i), find(i + N)), max(find(i), find(i + N))}] - mpiii[{find(i), find(i)}] - mpiii[{find(i + N), find(i + N)}];
  }
  return ans;
}

int main()
{
  int N, M;
  scanf("%d%d", &N, &M);
  vector<int> U, V;
  U.reserve(M);
  V.reserve(M);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    U.push_back(u);
    V.push_back(v);
  }
  vector<int> out = updown(N, M, U, V);
  for (int x : out)
  {
    printf("%d\n", x);
  }
  return 0;
}