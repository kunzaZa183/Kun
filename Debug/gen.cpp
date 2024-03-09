#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  const int n = 10, qs = 100;
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << rand() % n << " ";
  cout << "\n";
  cout << qs << "\n";
  for (int i = 0; i < qs; i++)
  {
    int b = rand() % n + 1;
    int a = rand() % b + 1;
    cout << a << " " << b << "\n";
  }
}