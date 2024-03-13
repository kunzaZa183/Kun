#include "capybara.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int fromr[maxn], froml[maxn], cangor[maxn], cangol[maxn];
int qsum[maxn];
vector<int> m, k;
int n;
int dist(int a, int b)
{
  if (a == b)
    return 0;
  if (a > b)
    swap(a, b);
  if (a == 0)
    return qsum[b - 1];
  return qsum[b - 1] - qsum[a - 1];
}

void gor(int cur, int furthest)
{
  if (cur == -1)
    return;
  if (cangor[cur] == -1)
  {
    cangor[cur] = furthest;
    gor(fromr[cur], furthest), gor(froml[cur], furthest);
  }
}

void gol(int cur, int furthest)
{
  if (cur == -1)
    return;
  if (cangol[cur] == -1)
  {
    cangol[cur] = furthest;
    gol(fromr[cur], furthest), gol(froml[cur], furthest);
  }
}

void capybara(int N, int Q, vector<int> M, vector<int> K)
{
  n = N;
  m = M, k = K;
  qsum[0] = K[0];
  for (int i = 1; i < K.size(); i++)
    qsum[i] += qsum[i - 1] + K[i];
  for (int i = 0; i < N; i++)
  {
    fromr[i] = -1;
    for (int j = i - 1; j >= 0; j--)
      if (dist(j, i) <= M[j])
      {
        fromr[i] = j;
        break;
      }
  }
  for (int i = 0; i < N; i++)
  {
    froml[i] = -1;
    for (int j = i + 1; j < N; j++)
      if (dist(j, i) <= M[j])
      {
        froml[i] = j;
        break;
      }
  }
  memset(cangor, -1, sizeof cangor), memset(cangol, -1, sizeof cangol);
  for (int i = N - 1; i >= 0; i--)
    gor(i, i);
  for (int i = 0; i < N; i++)
    gol(i, i);
  // for (int i = 0; i < N; i++)
  //   cout << fromr[i] << " ";
  // cout << "\n";
  // for (int i = 0; i < N; i++)
  //   cout << froml[i] << " ";
  // cout << "\n";
  // for (int i = 0; i < N; i++)
  //   cout << cangor[i] << " ";
  // cout << "\n";
  // for (int i = 0; i < N; i++)
  //   cout << cangol[i] << ' ';
  // cout << "\n";
}

long long travel(int A, int B)
{
  if (A < B)
  {
    int lowest = dist(A, B);
    for (int i = 0; i <= B; i++)
      if (cangor[i] >= B)
        lowest = min(lowest, dist(A, i));
    return max(m[A], lowest);
  }
  else if (A > B)
  {
    int lowest = dist(A, B);
    for (int i = B; i < n; i++)
      if (cangol[i] <= B)
        lowest = min(lowest, dist(A, i));
    return max(lowest, m[A]);
  }
  return m[A];
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int n, q, a, b;
  vector<int> m, k;
  assert(scanf("%d %d", &n, &q) == 2);
  for (int i = 0; i < n; i++)
  {
    assert(scanf("%d", &a) == 1);
    m.push_back(a);
  }
  for (int i = 0; i < n - 1; i++)
  {
    assert(scanf("%d", &a) == 1);
    k.push_back(a);
  }
  capybara(n, q, m, k);
  for (int i = 0; i < q; i++)
  {
    assert(scanf("%d %d", &a, &b) == 2);
    printf("%lld\n", travel(a, b));
  }
}
