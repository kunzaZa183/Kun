#include <bits/stdc++.h>
using namespace std;
#define int long long
const int arrsiz = 200000;

int seg[arrsiz * 4];

pair<int, int> lazy[arrsiz * 4];
int arr[arrsiz];

void build(int curin, int curl, int curr)
{
  if (curl == curr)
  {
    seg[curin] = arr[curl];
    return;
  }
  build(curin * 2 + 1, curl, (curl + curr) / 2), build(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
  seg[curin] = seg[curin * 2 + 1] + seg[curin * 2 + 2];
}

void lazyv(int curin, int curl, int curr)
{
  if (lazy[curin] != make_pair(0LL, 0LL))
  {
    seg[curin] += (lazy[curin].first + lazy[curin].second) * (curr - curl + 1) / 2;
    if (curl == curr)
    {
      lazy[curin] = {0LL, 0LL};
      return;
    }
    int mid = (curl + curr) / 2;
    int diff = (lazy[curin].second - lazy[curin].first) / (curr - curl);
    if (curin * 2 + 1 < 4 * arrsiz)
    {
      lazy[curin * 2 + 1].first += lazy[curin].first;
      lazy[curin * 2 + 1].second += (mid - curl) * diff + lazy[curin].first;
    }
    if (curin * 2 + 2 < 4 * arrsiz)
    {
      lazy[curin * 2 + 2].first += (mid - curl + 1) * diff + lazy[curin].first;
      lazy[curin * 2 + 2].second += lazy[curin].second;
    }
    lazy[curin] = {0LL, 0LL};
  }
}

void update(int curin, int curl, int curr, int ql, int qr)
{
  lazyv(curin, curl, curr);
  if (ql > curr || qr < curl)
    return;
  if (ql <= curl && curr <= qr)
  {
    lazy[curin] = {curl - ql + 1, curr - ql + 1};
    lazyv(curin, curl, curr);
    return;
  }
  update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr);
  update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr);
  seg[curin] = seg[curin * 2 + 1] + seg[curin * 2 + 2];
}

int query(int curin, int curl, int curr, int ql, int qr)
{
  lazyv(curin, curl, curr);
  if (ql > curr || qr < curl)
    return 0;
  if (ql <= curl && curr <= qr)
    return seg[curin];
  return query(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr) + query(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr);
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  build(0, 0, n - 1);
  for (int i = 0; i < 4 * arrsiz; i++)
    lazy[i] = {0LL, 0LL};
  while (q--)
  {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 1)
      update(0, 0, n - 1, a - 1, b - 1);
    else if (type == 2)
      cout << query(0, 0, n - 1, a - 1, b - 1) << '\n';
  }
}