#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("in.txt", "w", stdout);
  mt19937 mt(time(NULL));
  const int n = 5, q = 5;
  cout << n << " " << q << " 1\n";
  for (int i = 0; i < n; i++)
    cout << mt() % 10 + 1 << " ";
  vector<int> vi(n);
  for (int i = 1; i < n; i++)
    vi[i] = mt() % i;
  for (int i = 1; i < n; i++)
    cout << i << " " << vi[i] << "\n";
  for (int i = 0; i < q; i++)
    cout << mt() % (n - 1) << ' ' << mt() % n << ' ' << mt() % n + 1 << "\n";
}