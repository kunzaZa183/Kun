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
  const int n = 8;
  vector<int> vi;
  for (int i = 0; i < n; i++)
    vi.push_back(i + 1);
  shuffle(vi.begin(), vi.end(), default_random_engine(seed));
  cout << n << "\n";
  for (int i = 0; i < n; i++)
    cout << vi[i] << ' ';
  cout << "\n";
}