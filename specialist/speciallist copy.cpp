#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> children;
const int MOD = 1000000007;
vector<int> zvi, each;
vector<int32_t> ans;
vector<int> dfs(int cur)
{
  vector<int> thisone;
  for (auto a : children[cur])
  {
    vector<int> tmp = dfs(a);
    for (auto a : tmp)
      thisone.push_back(a);
  }
  thisone.push_back(each[cur]);
  for (auto a : zvi)
    thisone.push_back(a);
  sort(thisone.begin(), thisone.end(), greater<int>());
  int ansthis = 0;
  for (int i = 0; i < thisone.size(); i++)
    for (int j = 1; j < thisone.size(); j++)
      ansthis = (ansthis + thisone[i] - thisone[j]) % MOD;
  ans[cur] = ansthis;
  return thisone;
}
vector<int32_t> compute_cost(int32_t n, int32_t m, vector<int32_t> P, vector<int32_t> X, vector<int32_t> Z)
{
  children.resize(n);
  for (int i = 1; i < P.size(); i++)
    children[P[i]].push_back(i);
  for (auto &a : X)
    a = a * a;
  for (auto a : Z)
    zvi.push_back(a);
  for (auto &a : zvi)
    a = a * a;
  sort(zvi.begin(), zvi.end());
  ans.resize(n);
  for (auto &a : X)
    each.push_back(a);
  dfs(0);
  return ans;
}