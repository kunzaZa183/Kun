#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  int n = 4, m = 3;
  cout << n + 1 << ' ' << m << '\n';
  vector<int> allnumbers;
  for (int i = 0; i < n * m; i++)
    allnumbers.push_back(i / m + 1);
  vector<vector<int>> vvi(n + 1);
  srand(time(NULL));
  shuffle(allnumbers.begin(), allnumbers.end(), default_random_engine(rand()));
  vector<int> vi;
  for (int i = 0; i <= n; i++)
    vi.push_back(i);
  for (auto a : allnumbers)
  {
    int x = rand() % vi.size();
    vvi[vi[x]].push_back(a);
    if (vvi[vi[x]].size() == m)
      vi.erase(vi.begin() + x);
  }
  for (auto &a : vvi)
  {
    cout << a.size();
    for (auto b : a)
      cout << ' ' << b;
    cout << "\n";
  }
}