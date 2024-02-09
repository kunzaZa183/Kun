#include <bits/stdc++.h>
using namespace std;
int n = 4, extra = 1, ask = 3, del = 3;
vector<pair<int, int>> vpii;
vector<tuple<int, int, int>> allq;
int main()
{
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  vector<int> par(n);
  for (int i = 1; i < n; i++)
    par[i] = rand() % i;
  for (int i = 1; i < n; i++)
    vpii.emplace_back(par[i], i);
  set<pair<int, int>> spii;
  while (spii.size() < extra)
  {
    int a = 0, b = 0;
    while (a == b)
      a = rand() % n, b = rand() % n;
    if (a > b)
      swap(a, b);
    if (find(vpii.begin(), vpii.end(), make_pair(a, b)) == vpii.end())
      spii.emplace(a,b);
  }
  for (auto a : spii)
    vpii.push_back(a);

  vector<int> allnum;
  for (int i = 0; i < n; i++)
    allnum.push_back(i);
  for (int i = 0; i < del; i++)
  {
    int x = rand() % allnum.size();
    allq.emplace_back(1, allnum[x], 0);
    allnum.erase(allnum.begin() + x);
  }

  for (int i = 0; i < ask; i++)
    allq.emplace_back(2, rand() % n, rand() % n);

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  shuffle(allq.begin(), allq.end(), default_random_engine(seed));
  shuffle(vpii.begin(), vpii.end(), default_random_engine(seed));

  cout << n << " " << n - 1 + extra << ' ' << ask + del << " 2\n";
  for (auto a : vpii)
    cout << a.first << " " << a.second << "\n";
  for (auto [a, b, c] : allq)
    cout << a << ' ' << b << ' ' << c << '\n';
}
