#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

const int arrsiz = 3e5;
int seg[arrsiz * 4];
pair<int, int> lazy[arrsiz * 4];
int arr[arrsiz];

void lazyv(int curin, int curl, int curr)
{
  if (lazy[curin] != make_pair(0LL, 0LL))
  {
    seg[curin] = (lazy[curin].first + lazy[curin].second) * (curr - curl + 1) / 2;
    if (curl == curr)
    {
      lazy[curin] = {0LL, 0LL};
      return;
    }
    int mid = (curl + curr) / 2;
    int diff = (lazy[curin].second - lazy[curin].first) / (curr - curl);
    if (curin * 2 + 1 < 4 * arrsiz)
    {
      lazy[curin * 2 + 1].first = lazy[curin].first;
      lazy[curin * 2 + 1].second = (mid - curl) * diff + lazy[curin].first;
    }
    if (curin * 2 + 2 < 4 * arrsiz)
    {
      lazy[curin * 2 + 2].first = (mid - curl + 1) * diff + lazy[curin].first;
      lazy[curin * 2 + 2].second = lazy[curin].second;
    }
    lazy[curin] = {0LL, 0LL};
  }
}

void update(int curin, int curl, int curr, int ql, int qr, int start, int finish, int gap)
{
  lazyv(curin, curl, curr);
  if (ql > curr || qr < curl)
    return;
  if (ql <= curl && curr <= qr)
  {
    lazy[curin] = {start, finish};
    lazyv(curin, curl, curr);
    return;
  }
  update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, start, (start + finish) / 2, gap);
  update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, (start + finish) / 2 + gap, finish, gap);
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
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, q;
  cin >> n >> m >> q;
  tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> tii;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    x--;
    tii.insert(make_pair(x, 0));
  }
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    tii.find_by_order(i)->second = x;
  }
  auto it =tii.begin(),it2 = tii.begin();
  it2++;
  while (it2!=tii.end())
  {
    int dist = it->second -(it->first + 1);
    update(0,0,n-1,it->first + 1,it->second,dist * (dist),0)
  }
  
}