#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  const int n = 100000, qs = 100000;
  cout << n << ' ' << qs << "\n";
  vector<int> vi(n);
  for (int i = 1; i < n; i++)
  {
    vi[i] = rand() % i;
    cout << vi[i] + 1 << " " << i + 1 << "\n";
  }
  for (int i = 0; i < qs; i++)
  {
    int type = rand() % 2 + 1;
    cout << type << " ";
    if (type == 1)
    {
      int in = rand() % n, len = rand() % 6;
      cout << in + 1 << " " << len << "\n";
    }
    else
      cout << rand() % n + 1 << "\n";
  }
}