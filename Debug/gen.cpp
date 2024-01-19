#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  const int n = 10, maxtype = 4;
  cout << n << '\n';
  vector<int> vi;
  for (int i = 0; i < maxtype; i++)
    vi.push_back(i + 1);
  while (vi.size() < n)
    vi.push_back(rand() % maxtype + 1);
  for (int i = 0; i < n; i++)
    cout << vi[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; i++)
    cout << rand() % 20 + 1 << ' ';
  cout << '\n';
}