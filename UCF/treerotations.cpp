#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
struct node
{
  int id;
  node *l, *r;
  node()
  {
    l = NULL, r = NULL;
  }
} root;
void recur(node *cur)
{
  int x;
  cin >> x;
  if (x == 0)
  {
    cur->id = -1;
    cur->l = new node;
    recur(cur->l);
    cur->r = new node;
    recur(cur->r);
    return;
  }
  else
    cur->id = x;
}
pair<tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> *, int> small(node *cur)
{
  if (cur->id != -1)
  {
    auto *tmp = new tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
    tmp->insert(cur->id);
    return {tmp, 0};
  }
  auto leftside = small(cur->l);
  auto rightside = small(cur->r);
  if (leftside.first->size() < rightside.first->size())
    swap(leftside, rightside);
  int orderstays = 0, orderchanges = 0;
  
  for (auto a : *rightside.first)
  {
    orderstays += leftside.first->order_of_key(a);
    orderchanges += leftside.first->size() - leftside.first->order_of_key(a);
  }
  for(auto a:*rightside.first)
    leftside.first->insert(a);
  return {leftside.first, min(orderstays, orderchanges) + leftside.second + rightside.second};
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  recur(&root);
  cout << small(&root).second<<'\n';
}