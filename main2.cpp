#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a = 2'000'000'014, b = 100'000'000, mod = 1'000'000'007;
  cout << (a - b) % mod << '\n'
       << b % mod - a % mod << '\n'
       << b % mod << "\n"
       << a % mod << '\n';
}