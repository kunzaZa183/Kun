#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("in.txt", "w", stdout);
  mt19937 mt(time(NULL));
  cout << "1\n";
  const int n = mt() % 10, k = mt() % 2 * n + 1;
  cout << n << " " << k << "\n";
}