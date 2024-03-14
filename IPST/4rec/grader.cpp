#include "4rec.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500001;
map<int, vector<int>> mivi;
struct oset
{
  int fenwick[maxn],siz;
  oset()
  {
    memset(fenwick,0,sizeof fenwick);
  }
  void insert(int x)
  {
    siz++;
    for(int i = x;i<maxn;i+=i&(-i))
      fenwick[i]++;
  }
  void erase(int x)
  {
    siz--;
    for(int i=x;i<maxn;i+=i&(-i))
      fenwick[i]--;
  }
  int order_of_key(int x)
  {
    int sum = 0;
    for(int i = x;i>=1;i-=i&(-i))
      sum += fenwick[i];
    return sum;
  }
};
oset below, high;
int sth = 0;
set<int> allx;
vector<int> all;
long long find_rec(std::vector<std::vector<int>> Point, int P, int Q)
{
  for (auto a : Point)
  {
    mivi[a[1]].push_back(a[0]);
    allx.insert(a[0]);
  }
  all.push_back(INT_MIN);
  for (auto a : allx)
    all.push_back(a);
  long long total = 0;
  for (auto &a : mivi)
    for (auto b : a.second)
      high.insert(b);
  mivi.emplace(INT_MAX, vector<int>());
  for (auto a : mivi)
  {
    int maxl = 0, minr = all.size() - 1;
    int l = 0, r = all.size() - 1;
    // biggest 1-4 == +p
    while (l < r)
    {
      int mid = (l + r + 1) / 2;
      int valhigh = high.order_of_key(all[mid]);
      int vallow = below.siz - below.order_of_key(all[mid]);
      if (valhigh - vallow > P)
        r = mid - 1;
      else
        l = mid;
    }
    minr = min(minr, l);

    // smallest 4-1 == p
    l = 0, r = all.size() - 1;
    while (l < r)
    {
      int mid = (l + r) / 2;
      int valhigh = high.order_of_key(all[mid]);
      int vallow = below.siz - below.order_of_key(all[mid]);
      if (vallow - valhigh > P)
        l = mid + 1;
      else
        r = mid;
    }
    maxl = max(maxl, l);

    // smallest 2-3 == q
    l = 0, r = all.size() - 1;
    while (l < r)
    {
      int mid = (l + r) / 2;
      int valhigh = high.siz - high.order_of_key(all[mid]);
      int vallow = below.order_of_key(all[mid]);
      if (valhigh - vallow > Q)
        l = mid + 1;
      else
        r = mid;
    }
    maxl = max(maxl, l);

    // smallest 3-2 == q
    l = 0, r = all.size() - 1;
    while (l < r)
    {
      int mid = (l + r + 1) / 2;
      int valhigh = high.siz - high.order_of_key(all[mid]);
      int vallow = below.order_of_key(all[mid]);
      if (vallow - valhigh > Q)
        r = mid - 1;
      else
        l = mid;
    }
    minr = min(minr, r);

    total += max(0, minr - maxl + 1);
    for (auto b : a.second)
    {
      high.erase(b);
      below.insert(b);
    }
  }
  return total;
}
// int main()
// {
//   int N, P, Q;
//   scanf("%d %d %d", &N, &P, &Q);
//   std::vector<std::vector<int>> Point(N, std::vector<int>(2, 0));
//   for (int i = 0; i < N; i++)
//   {
//     scanf("%d %d", &Point[i][0], &Point[i][1]);
//   }
//   printf("%lld", find_rec(Point, P, Q));
// }
