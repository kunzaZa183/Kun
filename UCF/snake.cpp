#include <bits/stdc++.h>
using namespace std;
vector<int> seg, lazy;
void lazyv(int curin)
{
  if (curin * 2 + 1 < lazy.size())
    lazy[curin * 2 + 1] += lazy[curin];
  if (curin * 2 + 2 < lazy.size())
    lazy[curin * 2 + 2] += lazy[curin];
  seg[curin] += lazy[curin];
  lazy[curin] = 0;
}
void update(int curin, int curl, int curr, int ql, int qr, int val)
{
  lazyv(curin);
  if (ql > curr || qr < curl)
    return;
  if (ql <= curl && curr <= qr)
  {
    lazy[curin] += val;
    lazyv(curin);
    return;
  }
  update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, val), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, val);
  seg[curin] = max(seg[curin * 2 + 1], seg[curin * 2 + 2]);
}
int query(int curin, int curl, int curr, int ql, int qr)
{
  lazyv(curin);
  if (ql > curr || qr < curl)
    return INT_MIN;
  if (ql <= curl && curr <= qr)
    return seg[curin];
  int a = query(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr), b = query(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr);
  seg[curin] = max(a, b);
  return seg[curin];
}
int main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n, q;
    cin >> n >> q;
    seg.clear();
    lazy.clear();
    seg.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    while (q--)
    {
      int l, r, h;
      cin >> l >> r >> h;
      l--, r--;
      update(0, 0, n - 1, l, r, 1);
      if (seg[0] >= h)
        cout << "blocked\n";
      else
        cout << "hit\n";
    }
  }
}