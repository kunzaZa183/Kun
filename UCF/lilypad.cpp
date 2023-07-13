#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjlist;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n, m;
    cin >> n >> m;
    adjlist.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adjlist[a].push_back(b), adjlist[b].push_back(a);
    }
    
  }
}