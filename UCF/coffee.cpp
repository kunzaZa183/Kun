#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int a, b;
    cin >> a >> b;
    cout << a * b / 60 << '\n';
  }
}