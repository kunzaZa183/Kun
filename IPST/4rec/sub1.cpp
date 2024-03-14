
#include <stdio.h>
#include <vector>
#include <assert.h>
#include "4rec.h"
#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mivi;
vector<int> low, high;
set<int> si;
vector<int> vi;
long long find_rec(std::vector<std::vector<int>> Point, int P, int Q)
{
  for (auto a : Point)
  {
    mivi[a[1]].push_back(a[0]);
    high.push_back(a[0]);
    si.insert(a[0]);
  }
  vi.push_back(INT_MIN);
  for (auto a : si)
    vi.push_back(a);
  sort(high.begin(), high.end());
  mivi.emplace(INT_MAX, vector<int>());

  long long total = 0;
  for (auto &a : mivi)
  {
    for (auto b : vi)
    {
      int one = upper_bound(low.begin(), low.end(), b) - low.begin();
      int three = upper_bound(high.begin(), high.end(), b) - high.begin();
      int two = low.size() - one;
      int four = high.size() - three;
      if (abs(three - two) <= P && abs(one - four) <= Q)
      {
        total++;
        // cout << "ANS = " << a.first << ' ' << b << '\n';
      }
    }
    for (auto b : a.second)
    {
      high.erase(find(high.begin(), high.end(), b));
      low.push_back(b);
    }
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());
  }
  return total;
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
