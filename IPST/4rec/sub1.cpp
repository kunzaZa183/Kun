
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
    mivi[a[0]].push_back(a[1]);
    low.push_back(a[1]);
    si.insert(a[1]);
  }
  for(auto a:si)
    vi.push_back(a);
  sort(low.begin(), low.end());
  
  for (auto a : mivi)
  { 
    for(auto b:vi)
    {
      int one = find(low.begin(),low.end(),b) - low.begin();
      int three = find(high.begin(),high.end(),b) - high.begin();
      int two = low.size() - one;
      int four = high.size() - three;
      if(abs(three - two)<=P && abs(one - four)<=Q)

    }
    for (auto b : a.second)
    {
      low.erase(find(low.begin(), low.end(), b));
      high.push_back(b);
    }
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());
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
