#include <bits/stdc++.h>
using namespace std;
#define LSone(x) x & (-x)
#define int long long
struct query
{
  int l, r, val;
};
int fenwick[300002];

void update(int curin, int val)
{
  while (curin < 300002)
  {
    fenwick[curin] += val;
    curin += LSone(curin);
  }
}

unsigned long long qry(int curin)
{
  unsigned long long res = 0;
  while (curin > 0)
  {
    res += fenwick[curin];
    curin -= LSone(curin);
  }
  return res;
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> owns(n);
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    x--;
    owns[x].push_back(i);
  }
  vector<int> should(n);
  for (auto &a : should)
    cin >> a;
  int qs;
  cin >> qs;
  vector<query> vq(qs);
  for (auto &a : vq)
  {
    cin >> a.l >> a.r >> a.val;
    a.l--, a.r--;
  }
  vector<int> bsl(n, 1), bsr(n, qs);
  vector<bool> works(n, 0);
  vector<int> same(n, 0);
  while (1)
  {
    vector<pair<int, int>> vpii; // mid index
    for (int i = 0; i < n; i++)
      if (bsl[i] < bsr[i])
        vpii.emplace_back((bsl[i] + bsr[i]) / 2, i);
      else if (same[i] == 0)
      {
        same[i]++;
        vpii.emplace_back((bsl[i] + bsr[i]) / 2, i);
      }
    if (vpii.empty())
      break;
    sort(vpii.begin(), vpii.end());

    memset(fenwick, 0, sizeof fenwick);
    int in = 0;
    for (int i = 0; i < qs; i++)
    {
      if (vq[i].l <= vq[i].r)
      {
        update(vq[i].l + 1, vq[i].val);
        update(vq[i].r + 2, -vq[i].val);
      }
      else
      {
        update(vq[i].l + 1, vq[i].val);
        update(1, vq[i].val);
        update(vq[i].r + 2, -vq[i].val);
      }
      while (vpii[in].first == i + 1)
      {
        unsigned long long total = 0;
        for (auto a : owns[vpii[in].second])
        {
          total += qry(a + 1);
          if (total >= should[vpii[in].second])
          {
            bsr[vpii[in].second] = vpii[in].first;
            works[vpii[in].second] = 1;
            goto B;
          }
        }
        bsl[vpii[in].second] = vpii[in].first + 1;
      B:
        in++;
        if (in == vpii.size())
          goto A;
      }
    }
  A:;
  }
  for (int i = 0; i < n; i++)
    if (!works[i])
      cout << "NIE\n";
    else
      cout << bsl[i] << "\n";
}