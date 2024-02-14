#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000, days = 100;
int arr[maxn], dp[maxn][days + 1];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int maxi = -1;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, arr[i]);
    dp[i][1] = maxi;
  }
  for (int i = 2; i <= k; i++)
  {
    vector<int> vi;
    for (int j = i - 1; j < n; j++)
    {
      dp[j][i] = dp[j-1][i-1] + arr[j];
      while (!vi.empty())
        if (arr[j] > arr[vi.back()])
        {
          dp[j][i] = min(dp[j][i], dp[vi.back()][i] - arr[vi.back()] + arr[j]);
          vi.pop_back();
        }
        else
          break;
      if (!vi.empty())
        dp[j][i] = min(dp[j][i], dp[vi.back()][i] + arr[j]);
      vi.push_back(j);
    }
  }
  cout << dp[n - 1][k] << "\n";
}