#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000, BIGNUM = 1e9 + 1;
int type[maxn], weight[maxn], qsum[maxn];
int n;
int sumright(int a, int b)
{
  if (a < b)
  {
    if (a == 0)
      return qsum[b - 1];
    return qsum[b - 1] - qsum[a - 1];
  }
  if (a == b)
    return 0;
  int front;
  if (b == 0)
    front = 0;
  else
    front = qsum[b - 1];
  int back = qsum[n - 1] - qsum[a - 1];
  return back + front;
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> type[i];
  for (int i = 0; i < n; i++)
    cin >> weight[i];
  qsum[0] = weight[0];
  for (int i = 1; i < n; i++)
    qsum[i] = qsum[i - 1] + weight[i];
  vector<int> vi;
  for (int i = 0; i < n; i++)
    vi.push_back(i);
  int mini = INT_MAX;
  do
  {

    int sum = 0;
    for (int i = 1; i < vi.size(); i++)
      if (type[vi[i - 1]] > type[vi[i]])
        goto A;
    for (int i = 1; i < vi.size(); i++)
      sum += min(sumright(vi[i - 1], vi[i]), sumright(vi[i], vi[i - 1]));
    mini = min(mini, sum);
  A:;
  } while (next_permutation(vi.begin(), vi.end()));
  cout << mini << '\n';
}