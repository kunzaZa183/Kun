#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> vi(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> vi[i];
  vector<int> qsum(n + 1, 0);
  for (int i = 1; i <= n; i++)
    qsum[i] = qsum[i - 1] + vi[i];
  int cutoff = sqrt(q);
  vector<pair<int, int>> changelst;
  while (q--)
  {
    if (changelst.size() > cutoff)
    {
      // cout << "X\n";
      changelst.clear();
      fill(qsum.begin(), qsum.end(), 0);
      for (int i = 1; i <= n; i++)
        qsum[i] = qsum[i - 1] + vi[i];
    }
    int x;
    cin >> x;
    if (x == 1)
    {
      int k, u;
      cin >> k >> u;
      changelst.push_back({k, u - vi[k]});
      vi[k] = u;
    }
    else if (x == 2)
    {
      int a, b;
      cin >> a >> b;
      int sum = qsum[b] - qsum[a - 1];
      for (auto each : changelst)
        if (a <= each.first && each.first <= b)
          sum += each.second;
      cout << sum << '\n';
    }
  }
}