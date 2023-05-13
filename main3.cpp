#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("in.txt", "w", stdout);
  int n = 6, k = 3;
  cout << n << ' ' << k << '\n';
  vector<int> parent(n);
  parent[0] = -1;
  srand(time(NULL));
  set<int> si;
  while (si.size() < 3)
    si.insert(rand() % n);
  for (auto a : si)
    cout << a << ' ';
  cout << '\n';
  for (int i = 1; i < n; i++)
    cout << rand() % i << ' ' << i << ' ' << rand() % 10 + 1 << "\n";
  cout << '\n';
}