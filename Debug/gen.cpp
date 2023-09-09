#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  int n = 5, a = rand() % 10, b = rand() % 10, c = rand() % 10, x = rand() % 50;
  cout << n << ' ' << a << ' ' << b << ' ' << c << " " << x << "\n";
}