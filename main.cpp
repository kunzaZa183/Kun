#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n;
    vector<string> vvs(n);
    for (auto &a : vvs)
      cin >> a;
    vector<vector<vector<pair<int, int>>>> vvi(2);
    for (auto &a : vvi)
      a.resize(3);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (vvs[i][j] == 'X')
          vvi[0][(i + j) % 3].push_back({i, j});
        else if (vvs[i][j] == 'O')
          vvi[1][(i + j) % 3].push_back({i, j});
    int mini = INT_MAX;
    int minid, minj;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (i != j)
          if (vvi[0][i].size() + vvi[1][j].size() < mini)
          {
            mini = vvi[0][i].size() + vvi[1][j].size();
            minid = i, minj = j;
          }
    for (auto a : vvi[0][minid])
      vvs[a.first][a.second] = 'O';
    for (auto a : vvi[1][minj])
      vvs[a.first][a.second] = 'X';
    for (auto a : vvs)
      cout << a << '\n';
  }
}