#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  int n = 4, m = 3;
  cout << n + 1 << ' ' << m << '\n';
  vector<int> vi;
  vector<int> allnumbers;
  for (int i = 0; i < n * m; i++)
    allnumbers.push_back(i / m + 1);
  vector<vector<int>> vvi(n + 1);
  n *= m;
  for (int i = 0; i < vvi.size(); i++)
  {
    int some = rand() % min(n, m+1);
    for (int j = 0; j < some; j++)
    {
      int x = rand() % allnumbers.size();
      vvi[i].push_back(allnumbers[x]);
      allnumbers.erase(allnumbers.begin() + x);
    }
    n -= some;
  }
  for (auto &a : vvi)
  {
    cout << a.size();
    for (auto b : a)
      cout << ' ' << b;
    cout << "\n";
  }
}