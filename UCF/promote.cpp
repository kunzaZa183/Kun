#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
vector<int> parentvi;
vector<vector<int>> adjlist;
vector<int> vi;
vector<int> ans;
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
oset *dfs(int cur)
{
  // cout << cur << "\n";
  if (adjlist[cur].empty())
  {
    oset *tmp = new oset;
    tmp->insert(vi[cur]);
    return tmp;
  }
  vector<oset *> vo;
  for (auto a : adjlist[cur])
    vo.push_back(dfs(a));
  oset *maxi = vo.front();
  for (auto a : vo)
    if (a->size() > maxi->size())
      maxi = a;
  for (auto a : vo)
    if (a != maxi)
    {
      for (auto b : *a)
        maxi->insert(b);
    }
  ans[cur] = maxi->size() - maxi->order_of_key(vi[cur]);
  maxi->insert(vi[cur]);
  return maxi;
}
int main()
{
  // freopen("promote.in", "r", stdin);
  // freopen("promote.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi.resize(n);
  for (auto &a : vi)
    cin >> a;
  parentvi.resize(n);
  for (int i = 1; i < n; i++)
  {
    cin >> parentvi[i];
    parentvi[i]--;
  }
  adjlist.resize(n);
  for (int i = 1; i < n; i++)
    adjlist[parentvi[i]].push_back(i);
  ans.resize(n);
  dfs(0);
  for (auto a : ans)
    cout << a << '\n';
}