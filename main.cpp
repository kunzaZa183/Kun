// atcoder
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353, nums = 17;

int allways[(1 << nums)] = {}, connected[(1 << nums)] = {};
int fact[(1 << nums)];

int logpow(int a, int b)
{
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  int x = logpow(a, b / 2);
  if (b % 2 == 0)
    return x * x % MOD;
  return x * x % MOD * a % MOD;
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 1; i <= (1 << nums); i++)
    fact[i] = fact[i - 1] * i % MOD;
  int arr[nums] = {}, arr2[nums] = {};
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    arr[x - 1]++;
  }
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    arr2[x - 1]++;
  }
  int ways = 0;
  for (int i = 1; i < (1 << n); i++)
  {
    vector<int> all;
    for (int j = 0; j < n; j++)
      if (i & (1 << j))
        all.push_back(j);
    int sum = 0, sum2 = 0;
    for (auto a : all)
      sum += arr[a], sum2 += arr2[a];
    if (sum == sum2)
    {
      allways[i] = fact[sum];
      connected[i] = allways[i];
      for (int j = i - 1; j >= 0; j--)
      {
        j &= i;
        if (((1 << all.back()) & j) == 0)
          break;
        connected[i] = (connected[i] - connected[j] * allways[i ^ j] % MOD + MOD) % MOD;
      }
      ways = (ways + connected[i] * fact[m - sum] % MOD) % MOD;
    }
  }
  cout << ways * logpow(fact[m], MOD - 2) % MOD << '\n';
}