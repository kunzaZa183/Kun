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
    int n, a, b;
    cin >> n >> a >> b;
    vector<double> vd(n);
    for (auto &a : vd)
      cin >> a;
    sort(vd.begin(), vd.end());
    double sum = 0;
    for (int i = a; i < n - b; i++)
      sum += vd[i];
    cout << fixed << setprecision(20) << sum / (n - b - a) << "\n";
  }
}
