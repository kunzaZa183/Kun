#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  int n = 5, q = 5;
  cout << n << ' ' << q << "\n";
  for (int i = 0; i < n; i++)
    cout << rand() % 50 << ' ';
  cout << "\n";
  while (q--)
    cout << rand() % 2 + 1 << " " << rand() % n + 1 << ' ' << rand() % n + 1 << '\n';
}