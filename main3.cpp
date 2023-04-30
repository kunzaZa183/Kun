#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
struct edge
{
  int a, b, weight;
  friend bool operator<(edge a, edge x)
  {
    if (a.weight != x.weight)
      return a.weight < x.weight;
    if (a.a != x.a)
      return a.a < x.a;
    if (a.b != x.b)
      return a.b < x.b;
  }
};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  edge a = {1, 2, 3}, b = {1, 3, 4}, c = {3, 4, 3};
  tree<edge, null_type, less<edge>, rb_tree_tag, tree_order_statistics_node_update> pbds;
  pbds.insert(a), pbds.insert(b), pbds.insert(c);
  for (int i = 0; i < 3; i++)
  {
    edge x = *pbds.find_by_order(i);
    cout << x.a << ' ' << x.b << ' ' << x.weight << '\n';
  }
}