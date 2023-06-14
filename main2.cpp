#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int lcm = 1;
  for (int i = 1; i <= 16; i++)
  {
    lcm = lcm * i / __gcd(lcm, i);
    cout << lcm << '\n';
  }
}