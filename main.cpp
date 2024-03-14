#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
pair<int, int> arr[maxn], seg[4 * maxn];
pair<int, int> upd(pair<int, int> a, pair<int, int> b)
{
  vector<int> vi;
  vi.push_back(a.first | b.first);
  vi.push_back(a.first | b.second);
  vi.push_back(a.second | b.first);
  vi.push_back(a.second | b.second);
  sort(vi.begin(), vi.end(), greater<int>());
  return {vi[0], vi[1]};
}
void build(int curin, int curl, int curr)
{
  if (curl == curr)
  {
    seg[curin] = arr[curl];
    return;
  }
  build(curin * 2 + 1, curl, (curl + curr) / 2);
  build(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
  seg[curin] = upd(seg[curin * 2 + 1], seg[curin * 2 + 2]);
}
pair<int, int> query(int curin, int curl, int curr, int ql, int qr)
{
  if (ql > curr || qr < curl)
    return {0, 0};
  if (ql <= curl && curr <= qr)
    return seg[curin];
  return upd(query(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr), query(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr));
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < n; i++)
    {
      for (int j = 31; j > 0; j--)
      {
        int x = arr[i].first & (1 << j), y = arr[i].second & (1 << j);
        if (x != y)
        {
          
        }
      }
      // cout << "Each: " << arr[i].first << " " << arr[i].second << "\n";
    }
    build(0, 0, n - 1);
    int qs;
    cin >> qs;
    while (qs--)
    {
      int l, r;
      cin >> l >> r;
      cout << query(0, 0, n - 1, l - 1, r - 1).first << " ";
    }
    cout << '\n';
  }
}