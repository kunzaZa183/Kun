#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("in.txt", "w", stdout);
  int n = 10;
  srand(time(NULL));
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << rand() % 4999 + 1 << ' ' << rand() % 4999 + 1 << '\n';
}