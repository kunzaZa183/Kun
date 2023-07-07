#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int dp[31][31][436] = {};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dp[0][0][0] = 1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      
}