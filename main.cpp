#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500000, days = 100;
int arr[maxn], dp[maxn][2];
    vector<int> vi;
signed main()
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
    vi.clear();
    int cur = i%2;
    for (int j = i - 1; j < n; j++)
    {
      dp[j][cur] = dp[j-1][1 - cur] + arr[j];
      while (!vi.empty())
        if (arr[j] >= arr[vi.back()])
        {
          dp[j][cur] = min(dp[j][cur], dp[vi.back()][cur] - arr[vi.back()] + arr[j]);
          vi.pop_back();
        }
        else
          break;
      if (!vi.empty())
        dp[j][cur] = min(dp[j][cur], dp[vi.back()][cur]);
      vi.push_back(j);
    }
  }
  cout << dp[n - 1][k%2] << "\n";
}