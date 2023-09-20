// #include "panda.h"
#include <bits/stdc++.h>
using namespace std;

const int arrsiz = 100000, typesofl = 11;

vector<int> adjlist[arrsiz];
pair<int, int> closestto[arrsiz];

pair<int, int> status; // node dist
void dfs(int num)
{
  if (closestto[num] != make_pair(-1, -1))
    return;
  closestto[num] = status;
  for (auto a : adjlist[num])
  {
    status.second++;
    dfs(a);
    status.second--;
  }
}

void initialize(int N, int M, int S, vector<vector<int>> R)
{
  for (auto &a : R)
  {
    if (a.front() > a.back())
      swap(a.front(), a.back());
    if (a.front() + 1 != a.back() || a.front() >= S)
      adjlist[a.front()].push_back(a.back()), adjlist[a.back()].push_back(a.front());
  }
  for (int i = 0; i < N; i++)
    closestto[i] = {-1, -1};
  for (int i = 0; i < S; i++)
  {
    status = {i, 0};
    dfs(i);
  }
}

struct slope
{
  int x, y, sl;
  friend bool operator<(slope a, slope b)
  {
    if (a.sl > 0)
      return (a.y - a.x) < (b.y - b.x);
    return (a.x + a.y) < (b.x + b.y);
  }
  slope(int a, int b, int c)
  {
    x = a, y = b, sl = c;
  }
};
multiset<slope> pos[typesofl], neg[typesofl];

void panda_spawn(int P, int L, int X)
{
  neg[L].emplace(closestto[X].first, P - closestto[X].second * L, -L);
  pos[L].emplace(closestto[X].first, P - closestto[X].second * L, L);
}

void panda_evac(int P, int L, int X)
{
  neg[L].erase(pos[L].find({closestto[X].first, P - closestto[X].second * L, -L}));
  pos[L].erase(neg[L].find({closestto[X].first, P - closestto[X].second * L, L}));
}

int travel(int A, int B)
{
  int maxi = INT_MIN;
  for (int i = 0; i < typesofl; i++)
    if (!neg[i].empty())
    {
      slope x = *neg[i].rbegin();
      
    }
}