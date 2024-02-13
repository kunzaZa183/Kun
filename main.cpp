#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int qsum[maxn + 1];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    qsum[a]++;
    qsum[b + 1]--;
  }
  vector<int> vi;
  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    cur += qsum[i];
    vi.push_back(cur);
    // cout << cur << '\n';
  }
  sort(vi.begin(), vi.end());
  cout << vi[vi.size() / 2] << "\n";
}