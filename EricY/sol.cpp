#include <bits/stdc++.h>
using namespace std;
#define MOVE(a, b) vvi[b].push_back(vvi[a].back()), vvi[a].pop_back(), moves.emplace_back(a, b)
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vvi(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vvi[i].resize(x);
    for (auto &a : vvi[i])
      cin >> a;
  }
  vector<pair<int, int>> moves;
  for (int i = 0; i < n - 2; i++)
  {
    int in = i + 1;
    while (!vvi[i].empty())
      if (vvi[in].size() < m)
        MOVE(i, in);
      else
        in++;
    for (int j = i + 1; j < n; j++)
    {
      if (j != i + 1)
      {
        while (vvi[j - 1].size() < m)
          if (vvi[j].back() == i + 1)
            MOVE(j, i);
          else
            MOVE(j, j - 1);
      }
      for (int k = vvi[j].size() - 1; k >= 0; k--)
        if (vvi[j][k] == i + 1)
        {
          int ct = 0;
          while (vvi[j].back() != i + 1)
          {
            MOVE(j, i);
            ct++;
          }
          int temp;
          if (j == i + 1)
            temp = j + 1;
          else
            temp = j - 1;
          MOVE(temp, i);
          MOVE(j, temp);
          ct++;
          while (ct--)
            MOVE(i, j);
          MOVE(temp, i);
          while (vvi[j].back() == i + 1)
          {
            MOVE(j, i);
            if (vvi[j].empty())
              break;
          }
          if (!vvi[j].empty())
          {
            MOVE(j, temp);
            k = vvi[j].size();
          }
        }
    }
  }
  cout << moves.size() << "\n";
  reverse(moves.begin(), moves.end());
  for (auto &a : moves)
    cout << a.second + 1 << " " << a.first + 1 << "\n";
}