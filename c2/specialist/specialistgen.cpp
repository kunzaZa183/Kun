#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 10, m = 3;
  freopen("specialistin.txt", "w", stdout);
  cout << n << ' ' << m << '\n';
  for (int i = 1; i < n; i++)
    cout << rand() % i << " ";
  cout << '\n';
  for (int i = 0; i < n; i++)
    cout << rand() % 5 + 1 << ' ';
  cout << '\n';
  for (int i = 0; i < m; i++)
    cout << rand() % 5 + 1 << ' ';
  cout << '\n';
}