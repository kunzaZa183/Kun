#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")


#include <bits/stdc++.h>
using namespace std;
struct segtype
{
  int lazy;
  int prefs, prefp, sufs, sufp, ansp, anss;
  int allp, alls;
};
vector<segtype> seg;
string s;
void build(int curin, int curl, int curr)
{
  if (curl == curr)
  {
    if (s[curl] == 'S')
      seg[curin] = { 0, 1, 0, 1, 0, 0, 1, 0, 1 };
    else if (s[curr] == 'P')
      seg[curin] = { 0, 0, 1, 0, 1, 1, 0, 1, 0 };
    return;
  }
  build(curin * 2 + 1, curl, (curl + curr) / 2), build(curin * 2 + 2, (curl + curr) / 2 + 1, curr);

  seg[curin].allp = seg[curin * 2 + 1].allp && seg[curin * 2 + 2].allp;
  seg[curin].alls = seg[curin * 2 + 1].alls && seg[curin * 2 + 2].alls;
  seg[curin].ansp = max({ seg[curin * 2 + 1].ansp, seg[curin * 2 + 2].ansp, seg[curin * 2 + 1].sufp + seg[curin * 2 + 2].prefp });
  seg[curin].anss = max({ seg[curin * 2 + 1].anss, seg[curin * 2 + 2].anss, seg[curin * 2 + 1].sufs + seg[curin * 2 + 2].prefs });
  seg[curin].prefs = max(seg[curin * 2 + 1].prefs, seg[curin * 2 + 1].alls ? (curl + curr) / 2 - curl + 1 + seg[curin * 2 + 2].prefs : 0);
  seg[curin].prefp = max(seg[curin * 2 + 1].prefp, seg[curin * 2 + 1].allp ? (curl + curr) / 2 - curl + 1 + seg[curin * 2 + 2].prefp : 0);
  seg[curin].sufs = max(seg[curin * 2 + 2].sufs, seg[curin * 2 + 2].alls ? curr - (curl + curr) / 2 + seg[curin * 2 + 1].sufs : 0);
  seg[curin].sufp = max(seg[curin * 2 + 2].sufp, seg[curin * 2 + 2].allp ? curr - (curl + curr) / 2 + seg[curin * 2 + 1].sufp : 0);
}
void lazyv(int cur)
{
  if (seg[cur].lazy == 1)
  {
    swap(seg[cur].prefp, seg[cur].prefs);
    swap(seg[cur].sufp, seg[cur].sufs);
    swap(seg[cur].ansp, seg[cur].anss);
    swap(seg[cur].allp, seg[cur].alls);
    seg[cur].lazy = 0;
    if (cur * 2 + 1 < seg.size())
      seg[cur * 2 + 1].lazy = !seg[cur * 2 + 1].lazy;
    if (cur * 2 + 2 < seg.size())
      seg[cur * 2 + 2].lazy = !seg[cur * 2 + 2].lazy;
  }
}
void update(int curin, int curl, int curr, int ql, int qr)
{
  lazyv(curin);
  if (ql > curr || qr < curl)
    return;
  if (ql <= curl && curr <= qr)
  {
    seg[curin].lazy = 1;
    lazyv(curin);
    return;
  }
  update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr);

  seg[curin].allp = seg[curin * 2 + 1].allp && seg[curin * 2 + 2].allp;
  seg[curin].alls = seg[curin * 2 + 1].alls && seg[curin * 2 + 2].alls;
  seg[curin].ansp = max({ seg[curin * 2 + 1].ansp, seg[curin * 2 + 2].ansp, seg[curin * 2 + 1].sufp + seg[curin * 2 + 2].prefp });
  seg[curin].anss = max({ seg[curin * 2 + 1].anss, seg[curin * 2 + 2].anss, seg[curin * 2 + 1].sufs + seg[curin * 2 + 2].prefs });
  seg[curin].prefs = max(seg[curin * 2 + 1].prefs, seg[curin * 2 + 1].alls ? (curl + curr) / 2 - curl + 1 + seg[curin * 2 + 2].prefs : 0);
  seg[curin].prefp = max(seg[curin * 2 + 1].prefp, seg[curin * 2 + 1].allp ? (curl + curr) / 2 - curl + 1 + seg[curin * 2 + 2].prefp : 0);
  seg[curin].sufs = max(seg[curin * 2 + 2].sufs, seg[curin * 2 + 2].alls ? curr - (curl + curr) / 2 + seg[curin * 2 + 1].sufs : 0);
  seg[curin].sufp = max(seg[curin * 2 + 2].sufp, seg[curin * 2 + 2].allp ? curr - (curl + curr) / 2 + seg[curin * 2 + 1].sufp : 0);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, qs;
  cin >> n >> qs;
  cin >> s;
  seg.resize(4 * n);
  build(0, 0, n - 1);
  while (qs--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    update(0, 0, n - 1, l, r);
    cout << seg[0].anss << " " << seg[0].ansp << "\n";
  }
}