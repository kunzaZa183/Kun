#include <stdio.h>
#include <vector>
#include <assert.h>
#include "4rec.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
map<int, vector<int>> mivi;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;
oset below, high;
int sth = 0;
long long func(oset &big, oset &small)
{
}
long long find_rec(std::vector<std::vector<int>> Point, int P, int Q)
{
  for (auto a : Point)
    mivi[a[0]].push_back(a[1]);
  long long all = 0;
  for (auto &a : mivi)
    for (auto b : a.second)
      high.insert({b, sth++});
  for (auto a : mivi)
  {
    int maxl = 0, minr = 500000;
    int l = 0, r = 500000;
    // smallest 1-4 == +p
    while (l < r)
    {
      int mid = (l + r + 1) / 2;
      int valhigh = high.order_of_key({mid, INT_MAX});
      int vallow = below.size() - below.order_of_key({mid, INT_MAX});
      if (valhigh - vallow > P)
        r = mid - 1;
      else
        l = mid;
    }
    maxl = max(maxl, l);

    // smallest -4 == -p
    l = 0, r = 500000;
    while(l<r)
    {
      int mid = (l+r)/2;
      int valhigh = high.order_of_key({mid, INT_MAX});
      int vallow = below.size() - below.order_of_key({mid, INT_MAX});
      if(valhigh)
    }

    for (auto b : a.second)
    {
      high.erase(high.lower_bound({b, INT_MIN}));
      below.insert({b, sth++});
    }
  }
  return 0;
}
int main()
{
  int N, P, Q;
  scanf("%d %d %d", &N, &P, &Q);
  std::vector<std::vector<int>> Point(N, std::vector<int>(2, 0));
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &Point[i][0], &Point[i][1]);
  }
  printf("%lld", find_rec(Point, P, Q));
}
