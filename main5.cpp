#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  mt19937 mt(time(NULL));
  freopen("in.txt","w",stdout);
  const int n = 1000;
  cout << n << "\n";
  for (int i = 0; i < n; i++)
    cout << mt() % 10 << "\n";
}