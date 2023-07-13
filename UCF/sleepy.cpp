#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ti;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> vi(n);
  for (auto &a : vi)
    cin >> a;
  int wrong = -1;
  for (int i = 0; i < n - 1; i++)
    if (vi[i] > vi[i + 1])
      wrong = i;
  if (wrong == -1)
  {
    cout << "0\n";
    return 0;
  }
  cout << wrong + 1 << '\n';
  for (int i = wrong + 1; i < n; i++)
    ti.insert(vi[i]);
  for (int i = 0; i <= wrong; i++)
  {
    cout << (wrong - i) + ti.order_of_key(vi[i]);
    if (i != wrong)
      cout << ' ';
    ti.insert(vi[i]);
  }
  cout << "\n";
}
