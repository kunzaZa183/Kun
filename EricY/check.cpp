#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("output.txt", "r", stdin);
  freopen("result.txt", "w", stdout);
  int num = 5, per = 3;
  vector<vector<int>> vvi(num);
  for (int i = 0; i < num - 1; i++)
  {
    for (int j = 0; j < per; j++)
      vvi[i].push_back(i + 1);
  }
  int turns;
  cin >> turns;
  for (int i = 0; i < turns; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (!vvi[a].empty() && vvi[b].size() < per)
    {
      vvi[b].push_back(vvi[a].back());
      vvi[a].pop_back();
    }
    else
    {
      cout << vvi[a].size() << " " << vvi[b].size() << "\n";
      cout << "INVALID ON STEP " << i << '\n';
      exit(0);
    }
  }
  cout << "CORRECT\n";
}