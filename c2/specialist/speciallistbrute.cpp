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
  int ansthis = 0;
  for (int i = 0; i < thisone.size(); i++)
    for (int j = 0; j < thisone.size(); j++)
      if (thisone[i] > thisone[j])
        ansthis = (ansthis + thisone[i] - thisone[j]) % MOD;
  for (auto a : zvi)
    thisone.pop_back();
  ans[cur] = ansthis;
  return thisone;
}
vector<int32_t> compute_cost(int32_t n, int32_t m, vector<int32_t> P, vector<int32_t> X, vector<int32_t> Z)
{
  children.resize(n);
  for (int i = 1; i < P.size(); i++)
    children[P[i]].push_back(i);
  for (auto &a : X)
    each.push_back(a);
  for (auto &a : each)
    a = a * a;
  for (auto a : Z)
    zvi.push_back(a);
  for (auto &a : zvi)
    a = a * a;
  ans.resize(n);
  dfs(0);
  return ans;
}

int32_t main()
{
  int32_t dummy;
  int32_t N, M;
  std::vector<int32_t> P;
  std::vector<int32_t> X;
  std::vector<int32_t> Z;
  freopen("specialistin.txt","r",stdin);
  dummy = scanf("%d %d", &N, &M);
  P.push_back(-1);
  for (int i = 0; i < N - 1; i++)
  {
    int pp;
    dummy = scanf("%d", &pp);
    P.push_back(pp);
  }
  for (int i = 0; i < N; i++)
  {
    int xx;
    dummy = scanf("%d", &xx);
    X.push_back(xx);
  }
  for (int i = 0; i < M; i++)
  {
    int zz;
    dummy = scanf("%d", &zz);
    Z.push_back(zz);
  }
  std::vector<int32_t> res = compute_cost(N, M, P, X, Z);
  for (int r : res)
  {
    printf("%d\n", r);
  }
}
