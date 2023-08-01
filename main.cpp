#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int dp[31][31][436] = {};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i; i < fact.size(); i++)
    fact[i] = fact[i - 1] * i % MOD;
  vector<int> invfact;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k < m; k++)
      {
        for (int l = 0; l <)
      }
}